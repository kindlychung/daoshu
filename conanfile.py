
from conans import ConanFile, CMake, tools
from pathlib import Path
from conans.tools import os_info, SystemPackageTool

import os
import shutil

homedir = Path.home()
conan_dir = os.path.join(homedir, ".conan")
conan_bin_dir = os.path.join(conan_dir, "bin")
local_app_dir = os.path.join(homedir, ".local", "share", "applications")
if not os.path.exists(conan_bin_dir):
    os.mkdir(conan_bin_dir)


def icon_dir(i):
    p = os.path.join(homedir, ".local", "share", "icons",
                     "hicolor", "{}x{}".format(i, i), "apps")
    if not os.path.exists(p):
        Path(p).mkdir(parents=True, exist_ok=True)
    return p


class daoshuConan(ConanFile):
    name = "daoshu"
    version = "0.0.3"
    license = "LGPL"
    author = "kaiyin keezhong@qq.com"
    url = "https://github.com/kindlychung/daoshu"
    description = "Count-down timer using Qt5 and libpulse"
    topics = ("cpp", )
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    requires = ("docopt.cpp/0.6.3",)
    generators = "cmake"
    exports_sources = "src/*"

    def system_requirements(self):
        pack_list = None
        if os_info.linux_distro == "ubuntu":
            pack_list = ["libpulse-dev", "libnotify-dev",
                         "libglib2.0-dev", "qtbase5-dev"]
        if pack_list:
            for p in pack_list:
                installer = SystemPackageTool()
                installer.install(p)

    def build(self):
        cmake = CMake(self)
        print(str(cmake.build_config))
        cmake.configure(source_folder="src")
        cmake.build()

    def package(self):
        self.copy("*", dst="bin", src="bin")
        self.copy("*", dst="dist", src="dist")

    def imports(self):
        self.copy("*", dst="include", src="include")
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*", dst="bin", src="lib", keep_path=False)

    def deploy(self):
        self.copy("*", src="bin", dst=conan_bin_dir)
        self.copy("daoshu.desktop", src="dist", dst=local_app_dir)
        for i_small in [16, 32, 48, 64]:
            self.copy("daoshu_small.svg", src="dist", dst=icon_dir(i_small))
        for i_big in [128, 256]:
            self.copy("daoshu.svg", src="dist", dst=icon_dir(i_big))

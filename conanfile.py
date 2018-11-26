
from conans import ConanFile, CMake, tools
from pathlib import Path
from conans.tools import os_info, SystemPackageTool

import os

homedir = Path.home()
conan_dir = os.path.join(homedir, ".conan")
conan_bin_dir = os.path.join(conan_dir, "bin")
local_app_dir = os.path.join(homedir, ".local", "share", "applications")
if not os.path.exists(conan_bin_dir):
    os.mkdir(conan_bin_dir)


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
    requires = ("Qt/5.11.2.1@jzien/dev", "docopt/0.6.2@conan/stable",)
    generators = "cmake"
    exports_sources = "src/*"

    def system_requirements(self):
        pack_name = None
        if os_info.linux_distro == "ubuntu":
            pack_name = ["libpulse-dev", "libnotify-dev",
                         "libglib2.0-dev", "libqt5widgets5"]
        if pack_name:
            installer = SystemPackageTool()
            installer.install(pack_name)

    def build(self):
        cmake = CMake(self)
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

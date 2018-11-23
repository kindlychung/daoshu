
from conans import ConanFile, CMake, tools
from pathlib import Path
import os

homedir = Path.home()
conan_dir = os.path.join(homedir, ".conan")
conan_bin_dir = os.path.join(conan_dir, "bin")
if not os.path.exists(conan_bin_dir):
    os.mkdir(conan_bin_dir)


class daoshuConan(ConanFile):
    name = "daoshu"
    version = "0.0.1"
    license = "LGPL"
    author = "kaiyin keezhong@qq.com"
    url = "https://github.com/kindlychung/daoshu"
    description = "An example of using the Qt5 conan package"
    topics = ("cpp", )
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    requires = ("Qt/5.11.2.1@jzien/dev", "docopt/0.6.2@conan/stable")
    generators = "cmake"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

    def package(self):
        self.copy("*", dst="bin", src="bin")

    def imports(self):
        self.copy("*", dst="include", src="include")
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*", dst="bin", src="lib", keep_path=False)

    def deploy(self):
        self.copy("*", src="bin", dst=conan_bin_dir)

![daoshu](daoshu_with_text.svg)

An example of using Qt5 conan package in a GUI project.

## Compile

```sh
cd daoshu
mkdir build
cd build
conan install --build missing ..
conan build ..
```

## Run

```sh
bin/daoshu
```

You should be able to see an analog clock app.

# todo: 
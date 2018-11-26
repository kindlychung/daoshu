![daoshu](daoshu_with_text.svg)

A count-down timer written in C++ and Qt5.

## Why

I am not happy with any of the timer apps on my system, so I reinvented the wheel. Why not?

> Tested only on Ubuntu 18.10, your mileage may vary.

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

## Screencast

![](daoshu.png)

# Todo: 

* Package and upload to snapcraft
* Send a notification when time is up (besides playing a sound).
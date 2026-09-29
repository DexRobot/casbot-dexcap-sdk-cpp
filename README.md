# DexCap C++ SDK for CASBOT

**版本**  V1.0.0

## 1 概述
CASBOT-DexCap C++ SDK为CASBOT定制版外骨骼及手柄设备提供了设备识别，连接管理，采集数据读取，等编程接口。

## **2. DexCap SDK目录结构**

### 2.1 目录结构布局

```
casbot-dexcap-sdk-cpp/
├── include/                       # 头文件目录，DexCap SDK开放的所有类型和接口声明的头文件均在该目录
│   ├── cpp                        # 提供C++类和接口声明的头文件的目录。C++开发者使用该目录下头文件提供的API
│       ├── DexCap.hpp             # 管理和控制DexCap设备套装的接口类DexCapSuit的声明
│       ├── TypeDef.hpp            # 使用DexCap设备套装所需的基本类型，常量，以及可访问的数据类型的声明
│       ├── Utils.hpp              # SDK提供的若干简单工具类，如常用的字符串和日期时间戳处理
│   ├── configuration.h            # 以C形式提供的基础类型，常量，以及扫描并识别可用的串口设备列表的接口。
│   ├── dexcap.h                   # 以C形式提供的DexCap设备套装的管理和数据获取接口，对应DexCap.hpp所提供的功能接口
│   ├── typedef.h                  # 以C形式提供的描述基础数据模型的结构体，基本类型等，TypeDef.hpp中的声明依赖该头文件
├── libs/                          # 动态库文件所在目录
│   ├── linux/                     # Linux平台动态库文件的目录
│       ├── x86_64/                # x86_64平台下Linux动态库文件的目录
│             ├── libDexCap.so     # DexCap SDK的x86_64 Linux(目前仅支持Ubuntu)平台动态库文件
│             ├── 其他              # 依赖的x86_64平台下其他第三方库
│       ├── aarch64/               # ARM64平台下Linux动态库文件的目录
│             ├── libDexCap.so     # DexCap SDK的arm64 Linux(目前仅支持Ubuntu)平台动态库文件
│             ├── 其他              # 依赖的arn64平台下其他第三方库
│   ├── windows/                   # Windows平台动态库文件的目录
│       ├── DexCap.dll             # DexCap SDK的.dll文件
│       ├── DexCap.lib             # DexCap SDK的.lib文件
│       ├── 其他                    # 依赖的windows平台下的其他第三方库
├── conf/                          # V3.5所使用的配置文件及脚本，V4用户请忽略
│     ├── 98-dexcap-libusb.rules   # 系统udev配置文件，自动配置串口设备权限
│     ├── env_setup.sh             # 环境配置文件，安装依赖库等
├── examples/                      # 动态库文件所在目录
│   ├── example.cpp                # C++示例代码
│   ├── c_example.c                # C示例代码
│   ├── example_defs.h             # 示例程序头文件
│   ├── CMakeLists.txt             # 构建示例程序的cmake工程文件
```
<br><br>


## **2.2 API Reference**

### [2.1. CPP API Reference(中文)](./docs/CPP-API-Reference-CHS.md)
### [2.1. CPP API Reference(English)](./docs/CPP-API-Reference-EN.md)


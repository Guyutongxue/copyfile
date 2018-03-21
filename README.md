# copyfile U盘后台复制程序

## 获取

- 如计算机已安装 MinGW ,使用 gcc 编译 C++ 源码即可。

```BAT
> g++ copyfile.cpp -o copyfile.exe
```

- 或者在 Releases 中直接下载压缩包解压即可。

## 使用

前台运行此程序，运行`copyfile.exe`即可。关闭窗口来结束运行。

后台运行此程序，执行`bg_run.vbs`。表面上不会发生什么。执行`shutdown.bat`来结束运行。
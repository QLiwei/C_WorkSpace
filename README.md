# 1 git commit 代码提交规范

## 1.1 commitizen

```
格式：
type(scope) : subject

( 1 ) type（必须） : commit 的类别，只允许使用下面几个标识：
feat : 新功能
fix : 修复bug
docs : 文档改变
style : 代码格式改变
refactor : 某个已有功能重构
perf : 性能优化
test : 增加测试
build : 改变了build工具 如 grunt换成了 npm
revert : 撤销上一次的 commit
chore : 构建过程或辅助工具的变动

( 2 ) scope（可选） : 用于说明 commit 影响的范围，比如数据层、控制层、视图层等等，视项目不同而不同。

( 3 ) subject（必须） : commit 的简短描述，不超过50个字符。
commitizen 是一个撰写合格 Commit message 的工具，
遵循 Angular 的提交规范。
```

## 1.2 设置git commit模板

```
( 1 ) 建立模板文件
在项目中建立 .git_template 文件，内容可以自定义：

type:
scope:
subject:
( 2 ) 设置模板
运行如下命令：

git config commit.template .git_template // 当前项目
<!-- git config commit.template .git_template // 全局设置 -->
( 3 ) 提交代码
先使用 git add 添加代码
使用 git commit 按照模板填写
最后 git push 推送到远端

优点：
规则可配置，更自由
配置方式简洁（只需添加配置文件）
缺点：
便利性差，每次都要用 vim 编辑器填写模板
易出错，没有可靠的校验方式
```

## 1.3 git命令

```
git init
git diff
git push -u origin master

 # 分支、合并历史
 git log --pretty=format:"%h %s" --graph
 
 # 切换分支
 git checkout 分支名
 
 # 查看所有分支
 git branch -a
 
 # 切换至指定commit 切换至当前commit-id之后 git log 看不到之后的提交信息
 git checkout commit-id

git stash
git fetch
git rebase origin/master
----- 解决冲突
git add 冲突文件
git rebase --continue
-----
git stash pop

git commit --amend

# 推送commit至远程xx分支
git push origin 分支名

```

# 2.本地代码格式化工具

## 2.1 Clang-format

- windows安装

[Release LLVM 15.0.5 · llvm/llvm-project · GitHub](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.5)

- VSCODE 安装C/C++插件，切换至per-release版本

- 设置C_Cpp:Clang_format_path为clang-format.exe路径

  ```
  vscode 设置搜索：@ext:ms-vscode.cpptools
  C_Cpp:Clang_format_path:
  LLVM\bin\clang-format.exe
  ```

- 格式化命令

  ```
  Shift + Alt + F
  ```

- 保存格式化

  ```shell
  # setting.json 配置
  "editor.formatOnSave":ture
  
  ```

- 格式化文件插件:Format Files

# 3.编程风格

## 3.1 RT_Thread编程风格

### 3.1.1 目录名称 

目录名称如果无特殊的需求，请使用全小写的形式；components->组件

### 3.1.2 文件命名

文件名称如果无特殊的需求(如果是引用其他地方，可以保留相应的名称)，请使用全小写的形式。

设备驱动源码文件：`drv_class.c` 的命名方式，如：

- drv_spi.c
- drv_gpio.c

### 3.1.3 头文件定义

C 语言头文件为了避免多次重复包含，需要定义一个符号。这个符号的定义形式请采用如下的风格：

```
#ifndef __FILE_H__
#define __FILE_H__
/* header file content */
#endif
```

即定义的符号两侧采用 “__” 以避免重名，另外也可以根据文件名中是否包含多个词语而采用 “_” 连接起来

### 3.1.4 文件头注释

在每个源文件文件头上，应该包括相应的版权信息，Change Log 记录：

```c
/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2006-03-18     Bernard      the first version
 * 2006-04-26     Bernard      add semaphore APIs
 */
```

例如采用如上的形式

### 3.1.5 结构体定义

结构体名称请使用小写英文名的形式，单词与单词之间采用 “_” 连接，例如：

```c
struct rt_list_node
{
    struct rt_list_node *next;
    struct rt_list_node *prev;
};
```

其中，**"{"，"}" 独立占用一行**，后面的成员定义使用缩进的方式定义。

结构体等的类型定义请以结构体名称加上 “_t” 的形式作为名称，例如：

```c
typedef struct rt_list_node rt_list_t;
```

因为内核中对象引用方便的缘故，采用了对象内核指针作为类型定义的形式，例如：

```c
typedef struct rt_timer* rt_timer_t;
```

### 3.1.6 宏定义

在RT-Thread中，请使用大写英文名称作为宏定义，单词之间使用 “_” 连接，例如:

```c
  #define RT_TRUE		1
```

### 3.1.7 函数名称、声明

函数名称请使用小写英文的形式，单词之间使用 “_” 连接。提供给上层应用使用的 API接口，必须在相应的头文件中声明；如果函数入口参数是空，必须使用 void 作为入口参数，例如：

```
rt_thread_t rt_thread_self(void);
```

内部静态函数命名：以下划线开头，使用 `_class_method` 格式，不携带`_rt_`开头，如内核或驱动文件中的函数命名：

```c
/* IPC object init */
static rt_err_t _ipc_object_init()

/* UART driver ops */
static rt_err_t _uart_configure()
static rt_err_t _uart_control()   
```

调用注册设备接口的函数命名：使用 `rt_hw_class_init()` 格式，举例：

```c
int rt_hw_uart_init(void)
int rt_hw_spi_init(void)
```

### 3.1.8 注释编写

请使用**英文**做为注释，使用中文注释将意味着在编写代码时需要来回不停的切换中英文输入法从而打断编写代码的思路。并且使用英文注释也能够比较好的与中国以外的技术者进行交流。

**语句注释**：

源代码的注释不应该过多，更多的说明应该是代码做了什么，仅当个别关键点才需要一些相应提示性的注释以解释一段复杂的算法它是如何工作的。对语句的注释只能写在它的**上方或右方**，其他位置都是非法的。

```c
/* 你的英文注释 */
```

**函数注释**：

```c
注释以 /** 开头，以 */ 结尾，中间写入函数注释，组成元素如下，每个元素描述之间空一行，且首列对齐：

@brief + 简述函数作用。在描述中，着重说明该函数的作用，每句话首字母大写，句尾加英文句号。

@note + 函数说明。在上述简述中未能体现到的函数功能或作用的一些点，可以做解释说明，每句话首字母大写，句尾加英文句号。

@see + 相关 API 罗列。若有与当前函数相关度较高的 API，可以进行列举。

@param + 以参数为主语 + be 动词 + 描述，说明参数的意义或来源。

@return + 枚举返回值 + 返回值的意思，若返回值为数据，则直接介绍数据的功能。

@warning + 函数使用注意要点。在函数使用时，描述需要注意的事项，如使用环境、使用方式等。每句话首字母大写，句尾加英文句号。
```

注释模版请参见：rt-thread/src/ipc.c 源码文件，英文注释请参考使用 grammarly 以及谷歌翻译。

```c

```

### 3.1.9 缩进及分行

缩进请采用 4 个空格的方式。如果没有什么特殊意义，请在 “{” 后进行分行，并在下一行都采用缩进的方式，例如：

```c
if (condition)
{
   /* others */
}
```

唯一的例外是 switch 语句，switch-case 语句采用 case 语句与 switch 对齐的方式，例如：

```c
switch (value)
{
case value1:
    break;
}
```

case 语句与前面的 switch 语句对齐，后续的语句则采用缩进的方式。分行上，如果没有什么特殊考虑，请**不要在代码中连续使用两个以上的空行**。

### 3.1.10 大括号与空格

从代码阅读角度，建议每个大括号单独占用一行，而不是跟在语句的后面，例如：

```c
if (condition)
{
	/* others */
}
```

匹配的大括号单独占用一行，代码阅读起来就会有相应的层次而不会容易出现混淆的情况。空格建议在非函数方式的括号调用前留一个空格以和前面的进行区分，例如：

```
if (x <= y)
{
    /* others */
}

for (index = 0; index < MAX_NUMBER; index ++)
{
    /* others */
}
```

建议在括号前留出一个空格(涉及的包括 if、for、while、switch 语句)，而运算表达式中，运算符与字符串间留一个空格。另外，不要在括号的表达式两侧留空格，例如：

```
1    if ( x <= y )
2    {
3        /* other */
4    }
```

这样括号内两侧的空格是不允许的。

### 3.1.11 trace、log信息

在 RT-Thread 中，普遍使用的 log 方式是 rt_kprintf。rt_kprintf 在 RT-Thread 被实现成一个采用轮询、非中断方式的字串输出，能够适合于在中断这类"即时"显示日志的场合。因为这种轮询方式的存在，也必然会影响到日志输出的时序关系。

建议在代码中不要频繁的使用 rt_kprintf 作为日志输出，除非你真正的明白，你的代码运行占用的时间多一些也没什么关系。

日志输出应该被设计成正常情况下是关闭状态(例如通过一个变量或宏就能够开启)，并且当真正输出日志时，日志是易懂易定位问题的方式。"天书式"的日志系统是糟糕的，不合理的。

### 3.1.12 函数

在内核编程中，函数应该尽量精简，仅完成相对独立的简单功能。函数的实现不应该太长，函数实现太长，应该反思能够如何修改(或拆分)使得函数更为精简、易懂。

### 3.1.13 对象

RT-Thread 内核采用了 C 语言对象化技术，命名表现形式是：对象名结构体表示类定义、对象名 + 动词短语形式表示类方法，例如：

```c
struct rt_timer
{
    struct rt_object parent;
    /* other fields */
};
typedef struct rt_timer* rt_timer_t;
```

结构体定义 rt_timer 代表了 timer 对象的类定义；

```c
rt_timer_t rt_timer_create(const char* name,
                           void (*timeout)(void* parameter), 
                           void* parameter,
                           rt_tick_t time, rt_uint8_t flag);
rt_err_t rt_timer_delete(rt_timer_t timer);
rt_err_t rt_timer_start(rt_timer_t timer);
rt_err_t rt_timer_stop(rt_timer_t timer);
```

rt_timer + 动词短语的形式表示能够应用于 timer 对象的方法。

在创建一个新的对象时，应该思考好，对象的内存操作处理：是否允许一个静态对象存在，或仅仅支持从堆中动态分配的对象。

### 3.1.14 格式化代码

用 astyle 自动格式化代码，参数如下：

```c
      --style=allman
      --indent=spaces=4
      --indent-preproc-block
      --pad-oper
      --pad-header
      --unpad-paren
      --suffix=none
      --align-pointer=name
      --lineend=linux
      --convert-tabs
      --verbose
```

能满足函数空格、缩进、函数语句等的规范。

使用 formatting 格式化

使用 formatting 扫描文件来格式化代码：formatting 可以满足编码规则的基本要求，如：

- 将源文件编码统一为 UTF-8
- 将 TAB 键替换为 4 空格
- 将每行末尾多余的空格删除，并统一换行符为 ‘\n’
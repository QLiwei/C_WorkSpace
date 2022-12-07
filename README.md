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

### 2.1.1 命令格式

```c
USAGE: clang-format [options] [<file> ...]
clang-format --help

// 基础使用
// 以LLVM代码风格格式化main.cpp, 结果输出到stdout
clang-format -style=LLVM main.cpp
// 以LLVM代码风格格式化main.cpp, 结果直接写到main.cpp
clang-format -style=LLVM -i main.cpp
// 当然也支持对指定行格式化，格式化main.cpp的第1，2行
clang-format -lines=1:2 main.cpp
```

### 2.1.2 使用.clang-format来实现自定义格式化

```c
// 导出.clang-format文件
// # 可选格式最好写预设那那几个写最接近你想要的格式. 比如我想要接近google C++ style的。 我就写-style=google
clang-format --style=可选格式名 -dump-config > .clang-format
// eg. 
clang-format --style=google -dump-config > .clang-format
```

**使用.clang-format 文件来自定义格式	-style=file**

一般取.clang-format或_clang-format，因为自定义的排版格式文件只有取这两种名字之一，才能被Clang-Format识别。

```c
# 格式化的结果打到stdout(终端上)
clang-format --style='file:.\.clang-format' .\05_control_statement_loop.c
# 直接修改到文件
clang-format --style='file:.\.clang-format' -i .\05_control_statement_loop.c
```

**.clang-format配置文件的各个选项的含义**

```YAML
---
# 语言: None, Cpp, Java, JavaScript, ObjC, Proto, TableGen, TextProto
Language:	Cpp
# BasedOnStyle:	LLVM
# 访问说明符(public、private等)的偏移
AccessModifierOffset:	-4
# 开括号(开圆括号、开尖括号、开方括号)后的对齐: Align, DontAlign, AlwaysBreak(总是在开括号后换行)
AlignAfterOpenBracket:	Align
# 连续赋值时，对齐所有等号
AlignConsecutiveAssignments:	true
# 连续声明时，对齐所有声明的变量名
AlignConsecutiveDeclarations:	true
# 左对齐逃脱换行(使用反斜杠换行)的反斜杠
AlignEscapedNewlinesLeft:	true
# 水平对齐二元和三元表达式的操作数
AlignOperands:	true
# 对齐连续的尾随的注释
AlignTrailingComments:	true
# 允许函数声明的所有参数在放在下一行
AllowAllParametersOfDeclarationOnNextLine:	true
# 允许短的块放在同一行
AllowShortBlocksOnASingleLine:	false
# 允许短的case标签放在同一行
AllowShortCaseLabelsOnASingleLine:	false
# 允许短的函数放在同一行: None, InlineOnly(定义在类中), Empty(空函数), Inline(定义在类中，空函数), All
AllowShortFunctionsOnASingleLine:	Empty
# 允许短的if语句保持在同一行
AllowShortIfStatementsOnASingleLine:	false
# 允许短的循环保持在同一行
AllowShortLoopsOnASingleLine:	false
# 总是在定义返回类型后换行(deprecated)
AlwaysBreakAfterDefinitionReturnType:	None
# 总是在返回类型后换行: None, All, TopLevel(顶级函数，不包括在类中的函数), 
#   AllDefinitions(所有的定义，不包括声明), TopLevelDefinitions(所有的顶级函数的定义)
AlwaysBreakAfterReturnType:	None
# 总是在多行string字面量前换行
AlwaysBreakBeforeMultilineStrings:	false
# 总是在template声明后换行
AlwaysBreakTemplateDeclarations:	false
# false表示函数实参要么都在同一行，要么都各自一行
BinPackArguments:	true
# false表示所有形参要么都在同一行，要么都各自一行
BinPackParameters:	true
# 大括号换行，只有当BreakBeforeBraces设置为Custom时才有效
BraceWrapping:   
  # class定义后面
  AfterClass:	false
  # 控制语句后面
  AfterControlStatement:	false
  # enum定义后面
  AfterEnum:	false
  # 函数定义后面
  AfterFunction:	false
  # 命名空间定义后面
  AfterNamespace:	false
  # ObjC定义后面
  AfterObjCDeclaration:	false
  # struct定义后面
  AfterStruct:	false
  # union定义后面
  AfterUnion:	false
  # catch之前
  BeforeCatch:	true
  # else之前
  BeforeElse:	true
  # 缩进大括号
  IndentBraces:	false
# 在二元运算符前换行: None(在操作符后换行), NonAssignment(在非赋值的操作符前换行), All(在操作符前换行)
BreakBeforeBinaryOperators:	NonAssignment
# 在大括号前换行: Attach(始终将大括号附加到周围的上下文), Linux(除函数、命名空间和类定义，与Attach类似), 
#   Mozilla(除枚举、函数、记录定义，与Attach类似), Stroustrup(除函数定义、catch、else，与Attach类似), 
#   Allman(总是在大括号前换行), GNU(总是在大括号前换行，并对于控制语句的大括号增加额外的缩进), WebKit(在函数前换行), Custom
#   注：这里认为语句块也属于函数
BreakBeforeBraces:	Custom
# 在三元运算符前换行
BreakBeforeTernaryOperators:	true
# 在构造函数的初始化列表的逗号前换行
BreakConstructorInitializersBeforeComma:	false
# 每行字符的限制，0表示没有限制
ColumnLimit:	200
# 描述具有特殊意义的注释的正则表达式，它不应该被分割为多行或以其它方式改变
CommentPragmas:	'^ IWYU pragma:'
# 构造函数的初始化列表要么都在同一行，要么都各自一行
ConstructorInitializerAllOnOneLineOrOnePerLine:	false
# 构造函数的初始化列表的缩进宽度
ConstructorInitializerIndentWidth:	4
# 延续的行的缩进宽度
ContinuationIndentWidth:	4
# 去除C++11的列表初始化的大括号{后和}前的空格
Cpp11BracedListStyle:	false
# 继承最常用的指针和引用的对齐方式
DerivePointerAlignment:	false
# 关闭格式化
DisableFormat:	false
# 自动检测函数的调用和定义是否被格式为每行一个参数(Experimental)
ExperimentalAutoDetectBinPacking:	false
# 需要被解读为foreach循环而不是函数调用的宏
ForEachMacros:	[ foreach, Q_FOREACH, BOOST_FOREACH ]
# 对#include进行排序，匹配了某正则表达式的#include拥有对应的优先级，匹配不到的则默认优先级为INT_MAX(优先级越小排序越靠前)，
#   可以定义负数优先级从而保证某些#include永远在最前面
IncludeCategories: 
  - Regex:	'^"(llvm|llvm-c|clang|clang-c)/'
    Priority:	2
  - Regex:	'^(<|"(gtest|isl|json)/)'
    Priority:	3
  - Regex:	'.*'
    Priority:	1
# 缩进case标签
IndentCaseLabels:	false
# 缩进宽度
IndentWidth:	4
# 函数返回类型换行时，缩进函数声明或函数定义的函数名
IndentWrappedFunctionNames:	false
# 保留在块开始处的空行
KeepEmptyLinesAtTheStartOfBlocks:	true
# 开始一个块的宏的正则表达式
MacroBlockBegin:	''
# 结束一个块的宏的正则表达式
MacroBlockEnd:	''
# 连续空行的最大数量
MaxEmptyLinesToKeep:	1
# 命名空间的缩进: None, Inner(缩进嵌套的命名空间中的内容), All
NamespaceIndentation:	Inner
# 使用ObjC块时缩进宽度
ObjCBlockIndentWidth:	4
# 在ObjC的@property后添加一个空格
ObjCSpaceAfterProperty:	false
# 在ObjC的protocol列表前添加一个空格
ObjCSpaceBeforeProtocolList:	true
# 在call(后对函数调用换行的penalty
PenaltyBreakBeforeFirstCallParameter:	19
# 在一个注释中引入换行的penalty
PenaltyBreakComment:	300
# 第一次在<<前换行的penalty
PenaltyBreakFirstLessLess:	120
# 在一个字符串字面量中引入换行的penalty
PenaltyBreakString:	1000
# 对于每个在行字符数限制之外的字符的penalty
PenaltyExcessCharacter:	1000000
# 将函数的返回类型放到它自己的行的penalty
PenaltyReturnTypeOnItsOwnLine:	60
# 指针和引用的对齐: Left, Right, Middle
PointerAlignment:	Left
# 允许重新排版注释
ReflowComments:	true
# 允许排序#include
SortIncludes:	true
# 在C风格类型转换后添加空格
SpaceAfterCStyleCast:	false
# 在赋值运算符之前添加空格
SpaceBeforeAssignmentOperators:	true
# 开圆括号之前添加一个空格: Never, ControlStatements, Always
SpaceBeforeParens:	ControlStatements
# 在空的圆括号中添加空格
SpaceInEmptyParentheses:	false
# 在尾随的评论前添加的空格数(只适用于//)
SpacesBeforeTrailingComments:	2
# 在尖括号的<后和>前添加空格
SpacesInAngles:	true
# 在容器(ObjC和JavaScript的数组和字典等)字面量中添加空格
SpacesInContainerLiterals:	true
# 在C风格类型转换的括号中添加空格
SpacesInCStyleCastParentheses:	true
# 在圆括号的(后和)前添加空格
SpacesInParentheses:	true
# 在方括号的[后和]前添加空格，lamda表达式和未指明大小的数组的声明不受影响
SpacesInSquareBrackets:	true
# 标准: Cpp03, Cpp11, Auto
Standard:	Cpp11
# tab宽度
TabWidth:	4
# 使用tab字符: Never, ForIndentation, ForContinuationAndIndentation, Always
UseTab:	Never
...
```

**注意： 一般不全部重定义规则, 提供了BasedOnStyle标识让我们来重定义部分格式**

```yaml
---
# We'll use defaults from the LLVM style, but with 4 columns indentation.
BasedOnStyle: LLVM
IndentWidth: 4
---
Language: Cpp
# Force pointers to the type for C++.
DerivePointerAlignment: false
PointerAlignment: Left
---
Language: JavaScript
# Use 100 columns for JS.
ColumnLimit: 100
---
Language: Proto
# Don't format .proto files.
DisableFormat: true
---
Language: CSharp
# Use 100 columns for C#.
ColumnLimit: 100
...
```

### 2.1.3 常用命令

```c
// 格式化C++项目的代码
find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;

// clang-format-diff.py脚本
//clang-format还提供一个clang-format-diff.py脚本，用来格式化patch，code review提交代码前，
// 格式化最新的commit，并直接在原文件上修改
git diff -U0 HEAD^ | clang-format-diff.py -i -p1
```







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
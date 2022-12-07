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

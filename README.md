# git commit 代码提交规范

## 1.commitizen

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

## 2.设置git commit模板

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

## 3.git命令

```
git init
git diff
git push -u origin master
```


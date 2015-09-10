##第七章 Linux 文件与目录管理##

###1.2 目录的相关操作： cd, pwd, mkdir, rmdir###

>- cd
    - # cd - 
        - 回到前面的目录
    
<br/>
>- pwd  ( 显示出当前所在的文件夹 )
    - pwd -P
        - 列出当前目录链接的地方
        
<br/>
>- mkdir (创建新目录)
    - mkdir -p test1/test2/test3/test4
        - 加 -p 选项 是 递归创建
    - mkdir -m 711 test2
        - 加 -p 选项 是 创建时赋予权限
    
<br/>
>- rmdir （删除空目录）
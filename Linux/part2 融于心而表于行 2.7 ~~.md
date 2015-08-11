##为part2 的续版 完成 2.7  -  2.10 章节的记录##

##目录:##

####2.7 解决上网问题####
<img src="images/2B.png" width="70%" height="70%" />

##2.7.1 了解IP地址##

>- IP 地址分为 IPv4 和 IPv6
>- IPv4
<br />
<img src="images/2.7.1A.png" width="70%" height="70%" />

##2.8.2 环境变量##
>- 更多环境变量信息: <a href="http://www.cnblogs.com/growup/archive/2011/07/02/2096142.html" >linux 环境变量</a>
<br />
 <img src="images/2.8.2.png" width="70%" height="70%" />

##2.8.3 bash配置文件##

在输入用户名和密码登陆之后 shell 才会启动，这是login shell。 
还有一种non-login shell ,不需要做重复的登录操作获取bash界面。


####1. 系统设置文件####
>- 只有 login shell 才会读取系统设置文件 /etc/profile ， 它是系统整体的配置文件，包含很多重要变量信息。每个用户登录后取得bash后一定会读取 /etc/profile 配置文件。

####2. 用户的个性设置文件####

>- login shell 读完 **/etc/profile** 配置文件后就读取用户的个人配置文件。
>- 个人配置文件主要有三个隐藏文件：
    - **~/.bash_profile**
        - 如果 **~/.bash_profile** 存在，bash就不会理睬剩下的两个文件
    - **~/.bash_login**
        - 如果 **~/.bash\_profile** 不存在，bash才会读取 **~/.bash\_login**
    - **~/.profile**
        - 如果前面两个文件都不存在，bash才会读取 **~/.profile**
>- 另外的几个用户个人文件：
    - **~/.bashrc**
        - 如果 ~/.bashrc 存在的话，~/.bash_profile还会调用它
    - **~/.bash_history**
        - 历史命令
    - **~/.bash_logout**
        - 此文件，可告诉系统在"我"离开之前要帮"我"做什么，如：备份等
        
        
####4. login shell 和 non login shell 整个配置文件处理流程图：####
<img src="images/2.8.3A.png" width="70%" height="70%" />
<img src="images/2.8.3B.png" width="70%" height="70%" />







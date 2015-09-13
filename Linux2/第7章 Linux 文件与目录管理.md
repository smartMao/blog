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

<br/>
###1.3  关於运行档路径的变量： $PATH###

>- 我们知道，大多数命令都是存放在 /bin/ 下，例如：在 shell 中输入 ls ，就是到 /bin 目录下找到 ls 这个文件.
>- 为什么我可以在任何地方运行/bin/ls这个命令呢？  因为 $PATH 环境变量的帮助
>- 当我们在运行一个命令的时候，举例来说『ls』好了，系统会依照PATH的配置去每个PATH定义的目录下搜寻档名为ls的可运行档， 如果在PATH定义的目录中含有多个档名为ls的可运行档，那么先搜寻到的同名命令先被运行！
    
>- [root@Lunatic ~]# echo $PATH
/usr/lib/qt-3.3/bin:/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin:/root/bin:/root

<br/>
>- 假设你是root，如果你将ls由/bin/ls移动成为/root/ls(可用『mv /bin/ls /root』命令达成)，然后你自己本身也在/root目录下， 请问(1)你能不能直接输入ls来运行？(2)若不能，你该如何运行ls这个命令？(3)若要直接输入ls即可运行，又该如何进行？
    - 因为 bash 是根据 $PATH 去找命令，如果 $PATH 中没有 /root 目录，那将 ls 放在 /root 目录下，bash是找不到这个命令的
    - 如果把 /bin/ls 移动到 /root/ls 还想运行 ls 命令的话，就把 /root 目录加入到 $PATH 中
    
<br/>
>- 如果我有两个ls命令在不同的目录中，例如/usr/local/bin/ls与/bin/ls那么当我下达 ls 的时候，哪个ls会被运行？
- 查询$PATH ，哪个目录被先查询到就执行哪个

<br/>
###2.1 文件与目录的检视： ls###

>- [root@www ~]# ls [-aAdfFhilnrRSt] 目录名称
[root@www ~]# ls [--color={never,auto,always}] 目录名称
[root@www ~]# ls [--full-time] 目录名称
选项与参数：
-a  ：全部的文件，连同隐藏档( 开头为 . 的文件) 一起列出来(常用)
-A  ：全部的文件，连同隐藏档，但不包括 . 与 .. 这两个目录
-d  ：仅列出目录本身，而不是列出目录内的文件数据(常用)
-f  ：直接列出结果，而不进行排序 (ls 默认会以档名排序！)
-F  ：根据文件、目录等资讯，给予附加数据结构，例如：
      *:代表可运行档； /:代表目录； =:代表 socket 文件； |:代表 FIFO 文件；
-h  ：将文件容量以人类较易读的方式(例如 GB, KB 等等)列出来；
-i  ：列出 inode 号码，inode 的意义下一章将会介绍；
-l  ：长数据串列出，包含文件的属性与权限等等数据；(常用)
-n  ：列出 UID 与 GID 而非使用者与群组的名称 (UID与GID会在帐号管理提到！)
-r  ：将排序结果反向输出，例如：原本档名由小到大，反向则为由大到小；
-R  ：连同子目录内容一起列出来，等於该目录下的所有文件都会显示出来；
-S  ：以文件容量大小排序，而不是用档名排序；
-t  ：依时间排序，而不是用档名。
--color=never  ：不要依据文件特性给予颜色显示；
--color=always ：显示颜色
--color=auto   ：让系统自行依据配置来判断是否给予颜色
--full-time    ：以完整时间模式 (包含年、月、日、时、分) 输出
--time={atime,ctime} ：输出 access 时间或改变权限属性时间 (ctime) 
                       而非内容变更时间 (modification time)
                       
<br/>
###2.2 复制、删除与移动： cp, rm, mv###
>- cp (复制文件或目录)
    - [root@www ~]# cp [-adfilprsu] 来源档(source) 目标档(destination)
[root@www ~]# cp [options] source1 source2 source3 .... directory
选项与参数：
**-a  ：相当於 -pdr 的意思，至於 pdr 请参考下列说明；(常用)**
-d  ：若来源档为连结档的属性(link file)，则复制连结档属性而非文件本身；
-f  ：为强制(force)的意思，若目标文件已经存在且无法开启，则移除后再尝试一次；
**-i  ：若目标档(destination)已经存在时，在覆盖时会先询问动作的进行(常用)**
-l  ：进行硬式连结(hard link)的连结档创建，而非复制文件本身；
    **-p  ：连同文件的属性一起复制过去，而非使用默认属性(备份常用)；**
**-r  ：递回持续复制，用於目录的复制行为；(常用)**
-s  ：复制成为符号连结档 (symbolic link)，亦即『捷径』文件；
-u  ：若 destination 比 source 旧才升级 destination ！
最后需要注意的，如果来源档有两个以上，则最后一个目的档一定要是『目录』才行！

<br/>
>- 范例二：变换目录到/tmp，并将/var/log/wtmp复制到/tmp且观察属性：
[root@www ~]# cd /tmp
[root@www tmp]# cp /var/log/wtmp . <==想要复制到目前的目录，最后的 . 不要忘
[root@www tmp]# ls -l /var/log/wtmp wtmp <= 列出两个不同目录的 wtmp
**-rw-rw-r--** 1 root utmp 96384 Sep 24 11:54 /var/log/wtmp
**-rw-r--r--** 1 root root 96384 Sep 24 14:06 wtmp
- 注意上面的特殊字体，在不加任何选项的情况下，文件的某些属性/权限会改变；
- 这是个很重要的特性！要注意喔！还有，连文件创建的时间也不一样了！
- 那如果你想要将文件的所有特性都一起复制过来该怎办？可以加上 -a 喔！如下所示：

<br/>
>- 复制文件时，不要改变文件的属性
[root@www tmp]# cp -a /var/log/wtmp wtmp_2
[root@www tmp]# ls -l /var/log/wtmp wtmp_2
-rw-rw-r-- 1 root utmp 96384 Sep 24 11:54 /var/log/wtmp
-rw-rw-r-- 1 root utmp 96384 Sep 24 11:54 wtmp_2
# 了了吧！整个数据特性完全一模一样ㄟ！真是不赖～这就是 -a 的特性！

<br/>
>- 用 cp 命令 默认是：目的档的拥有者通常变成会是命令操作者本身，所以如果不想变成操作者本身的权限，要加上 -a 
>- 但普通用户能否使用 cp 把操作者权限复制到新文件里，要看文件本身的权限是不是能给普通用户操作，由於vbird的身份并不能随意修改文件的拥有者与群组，因此虽然能够复制wtmp的相关权限与时间等属性， 但是与拥有者、群组相关的，原本vbird身份无法进行的动作，即使加上 -a 选项，也是无法达成完整复制权限的！


<br/>
###3.1 直接检视文件内容： cat, tac, nl###

>- cat  由第一行开始显示文件内容
>- tac  从最后一行开始显示，可以看出 tac 是 cat 的倒著写！
>- nl   显示的时候，顺道输出行号！
>- more 一页一页的显示文件内容
>- less 与 more 类似，但是比 more 更好的是，他可以往前翻页！
>- head 只看头几行
>- tail 只看尾巴几行
>- od   以二进位的方式读取文件内容！

###3.2 可翻页检视###

>- more (一页一页翻动)
    - # more install.log
>- more  的操作：
    - 空白键 (space)：代表向下翻一页；
    - Enter         ：代表向下翻『一行』；
    - /字串         ：代表在这个显示的内容当中，向下搜寻『字串』这个关键字；
    - :f            ：立刻显示出档名以及目前显示的行数；
    - q             ：代表立刻离开 more ，不再显示该文件内容。
    - b 或 [ctrl]-b ：代表往回翻页，不过这动作只对文件有用，对管线无用。

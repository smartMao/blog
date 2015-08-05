#第4章 安装Redhat 7.2

##目录：#
1. 主机的硬件配备与预计开放的服务
2. 硬盘规划
3. 多重操作系统的安装流程
4. Linux安装流程 (精简安装、完全安装)
5. 建立软盘开机片



##2. 硬盘规划##

硬盘 partition 的问题：
>- 在 Linux 底下，每一个装置都以一个档案来代表，例如 IDE1 的 master 为 /dev/hda ，而由于 primary + extended 最多有四个partition ，所以第一个由 extended 分割出来的 logical 扇区为 /dev/hda5 
    - 为什么是第一个分割的分区是 hda5，而不是  hda1 、 hda2 ...
    - hda5 : 
        - hd : Hard disk 硬盘
        - a  : 代表第一块硬盘
        - 5  : 代表第五个主分区 PS：因为Linux系统会给primary主分区预留4个分区，所以如果从extended扩展分区分割出来的, 即使是第一个分的，也要从5开始。
        
##分区类型：##
>- 主分区：最多只能有四个。
>- 扩展分区：
    - 扩展分区最多只能有一个，但他可以包含逻辑分区
    - 主分区 加 扩展分区 加起来最多只能有4个
    - 不能写入数据，只能包含逻辑分区      
        
>- 逻辑分区       

举例：如果你有一个硬盘接在 IDE2 的 master 上面，并且有 5 个可以使用的扇区，同时你分割了 2 个 primary partition (主分区)时，那么你的磁盘应该就会有底下几个代号：         
>- /dev/hdc1 (primary)          主分区
>- /dev/hdc2 (primary)
>- /dev/hdc5 (1st logical)      逻辑分区
>- /dev/hdc6 (2nd logical)
>- /dev/hdc7 (3th logical)




#第3章 简单的SPFdisk分割实例

##目录：##

1. 什么是硬盘分割？
2. SPFdisk
    - 2.1 删除原有分割
    - 2.2 建立主要分割扇区
    - 2.3 储存分割表
    - 2.4 格式化硬盘


##1.什么是硬盘分割？##
>- 不同的系统，所使用的file system 也是不相同的，比如：window                      用的是FAT格式，Linux用的是 ext2 格式。

>- 硬盘是以**sectors(扇区)、cylinder(磁柱)、 partitions(分割槽)** 作为储存的单位. 其中最小的硬盘单位是sectors。
    - 一个sectors 是 512 bytes 
    - 在进行格式化时,可将数个sectors格式化为一个逻辑扇区(logical block), 是一个 file system 的存取最小量  
    - partition(分割槽) : 就如同 windows 的 C: D: , 实际上他们都是同一个硬盘的，只是利用了『磁盘分割表』(partition table)来将实体的硬盘规划出不同的区块
    - primary (主分区) 和 extended(扩展分区)
        - primary (主分区)：最多只能分4个分区。 
        - extended(扩展分区)：扩展分区 最多可以分64以下.  
        
        
**举例**： 举个例子说，假设你的硬盘总共有 1024 个 cylinder （利用 blocks 结合而成的硬盘计算单位）， 那么你在这块硬盘的文件头地方 （就是磁盘分割表，可以想成要读取一块硬盘时最先读取的地方）如果写入你的 partitions 共有两块，一块是 primary 一块是 extended ，而且 extended 也只规划成一个logical ，那么你的硬盘就是只有两个槽啦（对于系统来说，真正能使用的有 Primary 与 Logical 的扇区， Extended 并无法直接使用的！需要再加以规划成为 Logical 才行！ ) ，而且在 partition table 也会记录 primary 是由『第 n1 个 cylinder 到第 n2 个 cylinder 』，所以啰，这样子一来，当系统要去读取 primary （就是 c 槽）的时后，就只会在！n1~n2 之间的实体硬盘当中活动

基本
上最多可以有 4 个 primary 的硬盘，而可以支持到 3 个 primary 与一个 extended ，其中， extended 若再细分成 logical 的话，则全部 primary + extended + logical 应该可以支持到 64 个之多
        
        
硬盘分割主要有以下几个步骤：
> 1. 将旧的分割表删除
> 2. 建立新的主分区 及 扩充分区   
> 3. 存储分割表
> 4. 已Dos工具格式化以分割硬盘  


























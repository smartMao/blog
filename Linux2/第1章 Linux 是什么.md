##第1章 Linux是什么##

###重点回顾###

 >- 计算机主要以二进制作为单位，而目前常用的磁盘容量单位为bytes，其单位换算为1Byte = 8bits， 其他的以1024为其倍数，如 1GByte=1024MBytes等等。
 >- 操作系统(Operation System)主要在管理与驱动硬件，因此必须要能够管理内存、管理装置、 负责行程管理以及系统呼叫等等。因此，只要能够让硬件准备妥当(Ready)的情况， 就是一个阳春的操作系统了。
 >- 最阳春的操作系统仅在驱动与管理硬件，而要使用硬件时，就得需要透过应用软件或者是壳程序(shell) 的功能，来呼叫操作系统操纵硬件工作。因此，目前称为操作系统的， 除了上述功能外，通常已经包含了日常工作所需要的应用软件在内了。
 >- Unix的前身是由贝尔实验室(Bell lab.)的Ken Thompson利用汇编语言写成的， 后来在1971-1973年间由Dennis Ritchie以C程序语言进行改写，才称为Unix。
 >- 1977年由Bill Joy释出BSD (Berkeley Software Distribution)，这些称为Unix-like的操作系统。
 >- 1984年由Andrew Tanenbaum制作出Minix操作系统，该系统可以提供原始码以及软件；
 >- 984年由Richard Stallman提倡GNU计划，倡导自由软件(Free software)， 强调其软件可以『自由的取得、复制、修改与再发行』，并规范出GPL授权模式， 任何GPL(General Public License)软件均不可单纯仅贩卖其软件，也不可修改软件授权。
 >- 1991年由芬兰人Linus Torvalds开发出Linux操作系统。简而言之，Linux成功的地方主要在于： Minix(Unix), GNU, Internet, POSIX 及虚拟团队的产生。
 >- Linux本身就是个最阳春的操作系统，其开发网站设立在http://www.kernel.org，我们亦称Linux操作系统最底层的数据为『核心(Kernel)』。
 >- 目前Linux核心的发展分为两种版本，分别是稳定版本的偶数版，如2.6.X，适合于商业与家用环境使用； 一种是发展中版本的奇数版如2.5.X 版，适合开发特殊功能的环境。
 >- Linux distributions的组成含有：『Linux Kernel + Free Software + Documentations(Tools) + 可完全安装的程序』所制成的一套完整的系统。
 
 
 <br/>
 ###本章习题###
 
 >- 请依据本章内容的说明，下载 Fedora 最新版本的 Live CD ，并将该 Live CD 刻录成为光盘 (或 DVD) 后， 调整你的主机 BIOS 成为使用光驱开机，在开机时放入刚刚刻录的 Live CD ，使用该光驱开机。在开机后你应该能够进入系统。 请进入该系统，尝试打开终端机、浏览器等，并尝试操作一下该系统。由于该系统并不会影响到你的硬盘数据， 请尽量玩玩！
    - 已安装 CentOS 6.5
>- 承上题，打开终端机并且输入『uname-r』这个指令，出现的核心版本为何？是稳定还是发展中版本？
>- 上网找出目前 Linux核心的最新稳定版与发展中版本的版本号码，请注明查询的日期与版本的对应。
    - 最新稳定：3.18 （2015.9.7）
    - 发展中：4.1.6 
>- 请上网找出 Linux 的吉祥物企鹅的名字，以及最原始的图档画面。(提示：请前往 http://www.linux.org 查阅)
    - Tux 
>- 你在你的主机上面安装了一张网络卡，但是开机之后，系统却无法使用，你确定网络卡是好的，那么可能的问题出在哪里？该如何解决？
    - 该网络卡的驱动没有安装
    - 硬件驱动的作用：设备驱动程序用来将硬件本身的功能告诉操作系统，完成硬件设备电子信号与操作系统及软件的高级编程语言之间的互相翻译。当操作系统需要使用某个硬件时，比如：让声卡播放音乐，它会先发送相应指令到声卡驱动程序，声卡驱动程序接收到后，马上将其翻译成声卡才能听懂的电子信号命令，从而让声卡播放音乐。
>- 我在一部主机上面安装Windows操作系统时，并且安装了显示适配器的驱动程序，他是没有问题的。但是安装Linux时，却无法完整的显示整个X Window。请问，我可不可以将Windows上面的显示适配器驱动程序拿来安装在Linux上？
    - 不可以，因为不同操作系统的程序不同，驱动自然就不同
>- 一个操作系统至少要能够完整的控制整个硬件，请问，操作系统应该要控制硬件的哪些单元？
    - 管理内存、管理装置、 负责行程管理、系统呼叫
>- 一个GBytes的硬盘空间，等于几个KBytes？
    - 1073741824 KBytes
>- 我在Windows上面玩的游戏，可不可以拿到Linux去玩？
    - 不可以，要看游戏开发商有没有在Linux平台上，开发这款游戏
>- Linux本身仅是一个核心与相关的核心工具而已，不过，他已经可以驱动所有的硬件， 所以，可以算是一个很阳春的操作系统了。经过其他应用程序的开发之后，被整合成为Linuxdistribitions。请问众多的distributions之间，有何异同？
    - 其实大多数系统都是大同小异，无非就是安装后的软件不同，还有一些插件，再后面是提供的服务
>- Unix 是谁写出来的？ GNU 计划是谁发起的？
    - Ritchie / 史托曼
>- GNU 的全名为何？他主要由那个基金会支持？
    - GNU's Not Unix  / FSF基金会
>- 何谓多人 ( Multi-user ) 多任务 ( Multitask )？
    - 多人：兼容分时系统：它可以让大型主机透过提供数个终端机(terminal)以联机进入主机，来利用主机的资源进行运算工作。
    - 多任务：CPU利用高速频率不断地在两个程序中交替运行（CPU运行下A 后又去运行下B，不断反复）
>- 简单说明 GNU General Public License ( GPL ) 与 Open Source 的精神：
    - GNU精神：写程序最大的快乐就是让自己发展的良好的软件让大家来使用了
    - GPL精神：使用者可以自由的执行、复制、再发行、学习、修改与强化自由软件。
>- 什么是 POSIX ?为何说 Linux 使用 POSIX 对于发展有很好的影响？
    -  POSIX(Portable Operating System Interface) 是一个家庭的标准IEEE计算机协会指定的维护操作系统之间的兼容性。POSIX定义了应用程序编程接口(API),连同命令
    - 因为POSIX标准主要是针对Unix与一些软件运行时候的标准规范， 只要依据这些标准规范来设计的核心与软件，理论上，就可以搭配在一起执行了
>- Linux 的发展主要分为哪两种核心版本？
    - 奇数版本是发展中版本，偶数版本是稳定版
>- 简单说明 Linux 成功的因素？
    - 1. 藉由 Minix 操作系统开发的 Unix like ，没有版权的纠纷；
2. 藉助于 GNU 计划所提供的各项工具软件， gcc/bash 等；
3. 藉由 Internet 广为流传；
4. 藉由支持 POSIX 标准，让核心能够适合所有软件的开发；
5. 托瓦兹强调务实，虚拟团队的自然形成！

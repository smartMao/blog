#### 《HTTP权威指南》 学习记录
<br />
**3.2.1 报文的语法**
>- 请求报文:

                <method> <request - URL> <version>
                <headers>
                
                <entity - body>

            
>- 响应报文:

                <version> <status> <reason - phrase>
                <headers>
                
                <entity - body>
                
<br />
 **4.1.1 TCP的可靠数据管道**
 
 
    HTTP连接实际上就是TCP连接和一些使用连接的规则。
    
    
<br />
**4.1.2 TCP流是分段的、由IP分组传送**

>- TCP的数据是通过名为IP分组 (或IP数据报) 的小数据块来发送的，按下图显示，HTTP就是 "HTTP over TCP over IP" 这个 
    "协议栈" 中的最顶层了。HTTP的安全版本HTTPS就是在 HTTP 和 TCP 之间插入了一个 (称为TLS 或 SSL) 的密码加密层。

<img src="images/4.1.2.png" width="700" height="265" />



<br />
**4.1.3 保持TCP连接的正确运行**

>- IP地址可以将你连接到正确的计算机，而端口号则可以将你连接到正确的应用程序上去。TCP连接是通过4个值来识别的：
                  < 源 IP 地址 、源端口号 |  目的 IP 地址 、 目的端口号 >
                  
>- 下图表示TCP连接当中的 IP分组(数据块) 中包含的参数、属性。
  <img src="images/4.1.3.png" /> 
  
>- 在下图中，有4条连接：A、B、C、D 
  <img src="images/4.1.3A.png" />
  <img src="images/4.1.3B.png" />
  
  **注意**：有些连接共享了相同的目的端口号 ( C 和 D 都使用目的端口号80 )，有些连接使用了相同的源IP地址( B 和 C )，
        有些使用了相同的目的IP地址 (A、B、C、D) 。但没有两个不同连接的所有4个值都一样的。(因为两条相同的TCP连接
        不能拥有4个完全相同的地址组件值)
        
  <br />
  
**4.3.1 常被误解的 connection 首部**
 
>- HTTP 的 Connection 首部字段中有一个由逗号分隔的<strong>连接标签列表</strong>，这些标签为此连接指定了一些不会，
   传播到其他连接中的去的选项，比如：可以用 connention ：close 来说明发送完下一条报文之后必须关闭的连接。
   
>- Connection 首部可以承载3种不同的类型标签：
  1.   HTTP首部字段名。
  2.   任意标签值，用于描述此连接的非标准选项。
  3.   值：close ， 说明操作完成后需关闭这条持久连接  
  
>- 如果连接标签中包含了一个HTTP首部字段的名称，那么这个首部字段就包含了与一些连接有关的信息，不能将其转发出去。
   在将报文转发出去之前，必须删除 Connection 首部列出的所有首部字段。
   
   <img src="images/4.3.1.png" />
   
>- HTTP 应用程序收到一条带有 Connection 首部的报文时，接收端会解析发送端请求的所有选项，并将其应用，然后会在将此报文
   转发给一下条地址之前，删除 Connection 首部以及 Connection 中列出的所有首部。
   
<br />

**4.5.3 keep-alive 操作**

>- 实现HTTP 1.0 keep-alive连接的客户端可以通过包含 Connection: Keep-Alive ; 首部请求将一条连接保持再打开的状态。
>- 如果服务器原因为一下条请求连接保持在打开状态，那么就会在响应首部中包含相同的首部(即:包含Connection: Keep-Alive)。
>- 如果响应首部没有Connection: Keep-Alive首部，客户端就认为服务器不支持 keep-alive ,会在发回响应报文之后关闭连接。

![4.5.3.png](images/4.5.3.png)
    
<br />

**4.5.5 Keep-Alive 连接的限制和规则**

>- 代理和网关都必须执行 Connection 首部的规则，代理或网关必须在将报文转发出去或将其高速缓存之前，删除在 Connection 
   首部中命名的所有首部字段以及 Connection 首部自身。
>- 严格来说，不应该与无法确定是否支持 Connection 首部的代理服务器建立 keey-alive 连接，以防止出现"哑代理"的问题
    
    
    
**4.5.6 Keep-Alive 和哑代理**

<img src="images/4.5.6A.png" width="70%" height="70%" />
<img src="images/4.5.6B.png" width="70%" height="70%" />
<img src="images/4.5.6C.png" width="70%" height="70%" />
<img src="images/4.5.6D.png" width="70%" height="70%" />
<img src="images/4.5.6E.png" width="70%" height="70%" />

<br />

####2.代理与逐跳首部####

>- 为了避免此类的通信问题的发生，现在的代理都绝不能转发 Connection 首部，或者其中的字段名。因此，一个代理收到了 
   Connection : keep-alive 首部，是不应该转发 Connection 首部，或所有名为 keey-alive 的首部。
>- 另外，还有几个不能作为 Connection 首部值列出，也不能被代理转发或作为缓存响应使用的首部。
    - Connection
    - Keep-Alive
    - Proxy-Authenticate
    - Proxy-Authorization
    - Trailer
    - TE
    - Transfer-Encoding
    - Upgrade

##4.5.8 HTTP 1.1 持久连接##

>- 与HTTP 1.0+ 的 keep-alive 连接不同，HTTP 1.1 持久连接在默认情况下是激活的。除非你特别指明，否则HTTP 1.1 假定
   所有的连接都是持久的。如果想要再事务处理结束之后将连接关闭，那么 HTTP 1.1 应用程序就必须向报文中添加一个：
   connection:close 首部。


##4.6 管道化连接##

<img src="images/4.6.png" width="60%" height="60%" />


##4.7.4 TCP正常关闭连接##
>- TCP 连接是双向的，TCP连接的每一端都有一个输入队列和一个输出队列，用于数据的读或写，放入一端的输出队列中的数据最终最
   出现在另一端的输入队列中。
   
   1. 完全关闭与半关闭
   2. TCP关闭及重置错误
  
<img src="images/4.7.4.png" width="60%" height="60%" />
<img src="images/4.7.4A.png" width="60%" height="60%" />
   
    


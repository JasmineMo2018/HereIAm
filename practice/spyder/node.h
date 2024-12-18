#pragma once
/*
    1. 创建型模式：对象创建
      单例 全局一个对象 ok ：a.构造是私有的，instance是static的，publicget也是static的 最好返回引用 构造函数default 拷贝&赋值 delete
                              b. new 加锁、两次判断、提供一个销毁函数 构造函数default 拷贝&赋值 delete
      工厂方法 ok ：做个手机 华为的 荣耀的 啥啥啥的 抽象出来一个工厂虚基类，然后你就继承吧
      抽象工厂 ok： 制造手机零部件
      建造者 ok： 一个对象 结构比较复杂。你把它拆开了去设置自己想要的零件类型
      原型
    2. 结构型模式：处理了类和对象间的组合
      适配器 ok：新接口旧接口不兼容 继承新接口 然后旧接口(需要适配的接口)对象为成员变量，去实现新接口的功能
      桥接 ok：红色 蓝色 球 长方形 混着来的不要排列组合  把类缩成指针 然后放在另一个功能类里面调用
      组合 ok：像是一个树，把大的类分解成小的，然后大的功能里面调用小的的相关方法
      装饰器 ok： 茶 加奶 加糖 加芋泥 加波波 加珍珠 加桂花冻
      外观 ok ：隐藏子系统的复杂
      享元 ok ：共享元素  大量相似元素 有点像一个查表过程。不存在就创建，扔表里面。需要就来查
      代理 ok: 间接 延迟加载   公司ban网站
    3. 行为型模式：类和对象交互中通信和职责分配
      访问者 ：最开始的基类，要添加功能。怎样不改继承的类的情况下，添加功能
      模板 ok： 定义好一个算法骨架public ，算法骨架里面调用protect的各个方法。子类去继承这个类，然后重写protect的方法
      策略 ok: 把一个算法类封装到使用它的类中，后面直接调用使用的接口就行了。重写算法类的对象传到使用接口的构造里面
      状态 ok：行为和状态分开，外部只管切换行为，内部去管理各个状态
      观察者 ok: 一对多 一个状态变化时通知所有关注的人
      备忘录 : 虚拟机快照 可以回滚
      中介者 ：聊天室
      迭代器 ok: 一系列的对象做一个统一、透明的访问
      解释器 
      命令 ok： 把封装成一个类，里面时一些行为。然后外面只管调用，内部有栈或者列表，按顺序执行命令(undo redo啥的、多线程队列)
      责任链 ok：创建一个请求的处理链，传下去， 直到有个对象可以处理这个请求。setnext 这样 ，然后
  */

/*
  基本设计原则
    1. 单一职责原则 ： 一个类只做一个事情
    2. 开闭原则： 可扩展 但是不要修改原有代码 (扩展开放、修改闭合)
    3. 里氏替换原则： 子类可以替换基类，但不会影响程序的正确性
    4. 依赖倒置原则： 高层模块不能依赖低层模块 ，可以让高层和底层都依赖抽象
    5. 接口隔离原则：一个接口只做一个事情，不要做和自己无关的
    6. 合成/聚合复用原则：has 替代 is
    7. 迪米特法则：最小支持原则 减少耦合
*/

/*
  架构设计模式：
      1. 微服务架构：互联网公司用的多。将软件系统分割成小型、自治的服务。每个服务负责一个特定的业务，独立部署、发布。
                      亚马逊、阿里巴巴、滴滴等
      2. 事件驱动架构：系统各个组件发布订阅事件，组件彼此之前不直接调用方法，而是发送事件交流
                      金融、证券、风险管理、电子商务、零售
      3. 分层架构：应用程序划分成多个逻辑层。每个层都有自己的逻辑。且为其他层服务
                  表示层：和用户ui交互
                  应用层：调用底层的服务，对上层的表示层的请求做处理
                  业务逻辑层：核心业务逻辑，流程转换，协调组件服务
                  数据访问层：数据库交互，增删改查

                  人力资源、啥的

      4. 服务器无状态架构：发起一个服务，不会保存客户的状态和信息。每次请求都是独立的。
                  容错性好，伸缩性强，安全性强

                  web应用 云 容器化 流媒体平台


    反应式设计模式：
      1. 熔断器：保护软件系统，极端情况下，免除事故发生。
              
      2. 限流：对资源管理提供的另外一种解决方案

      3. 响应式缓存模式：改善性能，对于经常访问的数据，缓存起来。高并发、低延时的

      4. 异步消息模式：实现组件解耦

    并发设计模式：
      1. 信号量模式
      2. 互斥锁模式
      3. 读写锁模式
      4. 生产者-消费者模式
      5. 轻量级任务模式

*/

/*
  反模式：一些陷阱的解决方案 （一些应该避免的失败的经验）
      1. 神秘代码：没有上下文说明、突兀、没有任何注释 啊 魔鬼数字 硬编码的常量值、路径、配置信息啥的
      2. 金丝雀代码：临时测某一个功能，就写了一个小代码，然后忘了
      3. 复制粘贴编程：通用方法写common里面。重复是软件开发万恶的本源
      4. 大球理论：有啥就实现，不考虑架构。扩展后维护不了
      5. 嵌套回调：开发过程中，回调方式过于复杂时
      6. 过渡工程：接口写好了，功能没实现，或者没弄通。别发布撒！而且发布前做灰度发布比较靠谱
      7. 神秘需求：用jira标所有需求，加注释。开发的时候要有需求文档、有消息要和业务主导人员和测试人员充分协商
      8. 僵化的层次结构：设计要花时间，不要上来就写，不要搞激进、临时、无法扩展的代码
      9. 过度优化：非要50行！非要50行！非要改！非要改！
*/

// 单例模式
/*
  动机：全局唯一的类的实例、全局共享状态或数据，或频繁创建可能带来的资源的成本过高
  注意：平台和机制限制和程序本身的行为是两回事


  1. 懒汉 or 饿汉： 饿汉-加载的时候就创建了 资源浪费；懒汉-用，才创建
  2. 懒汉模式的多线程考虑问题，double check
  3. C++11等最新的一些实现和关注点

*/

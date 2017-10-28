描述：给定一个二叉树，每一个二叉树的节点的值都是一个字符串，给定节点
node1和node2，求节点node1和node2的路径长度，如果node1和node2不是从根
节点出发的同一条路径上的节点则返回-1.此处一个子节点和父节点之间的路径长
度定位1.二叉树的输入使用二叉树的数组形式表示，在输入中如果表示null（空指针），
则使用字符串“NULL”表示。如二叉树
          aa
      bb        cc
    dd        ee   ff
  gg   hh    i  j k   l  
使用数组表示：
aa bb cc dd NULL ee ff gg hh i j k l
（注意这棵树中bb没有右节点）

在输入的时候，对于bb的右节点，因为没有子节点，则输入“NULL”表示。
为简化输入，我们给的测试用例的输入都是满二叉树的个数，对于
没有节点的所有位置在数组中都使用NULL填充

输入：
	step1：二叉树的节点个数（满二叉树，其中非叶节点空节点也算进去）m，
	step2：然后依次输入 m 个字符串，如果节点表示为null，使用字符串“NULL”表示。
	step3：节点node1的值（不会为“NULL”值）
	step4：节点node2的值（不会为“NULL”值）

输出：
节点node1和节点node2之间的路径长度（如果两个节点不在从根节点出发的一条
路径上，则返回-1）


注：此处的“NULL”在输入和输出时都表示字符串

示例1：
 输入： 
7
aa bb cc dd NULL ee ff 
aa
ee

 输出：
2（没有回车）


示例2：
 输入： 
7
aa bb cc dd NULL ee ff 
bb
ee

 输出：
-1（没有回车）
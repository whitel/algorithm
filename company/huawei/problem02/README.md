输入一个TLV（Type-Length-Value）数据包，由以下结构组成：tag, length, value。如：0F04ABABABAB，0F表示这个数据包的tag为16，04表示这个数据包的length为4，后面就是长度为4的value。
现在输入一个TLV数据包，并输入n，后接n个数据，请你返回查询的结果，如果查询成功输出数据包长度与在数据包中的offset，如果查询失败输出0 0。

输入：
0F04ABABABAB
2
15

输出：
4 2

输入：
0F04ABABABAB
2
16

输出：
0 0
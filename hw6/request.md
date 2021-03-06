法国外交家布莱斯·德·维吉尼亚（Blaise de Vigenère）发明了一种方法来对同一条信息中的不同字母用不同的密码进行加密。这样，同样的E在一个位置可能被M所取代，而在另一个位置的E则有可能以K的面目出现。这样，就可以防止任何人利用频率分析法解密该条信息。

维吉尼亚（Vigenere）密码的代换规则由26个类凯撒（Caesar）密码代换表构成,其中每个代换表是对明文字母表移位0到25次后得到的代换单表。
每个密码代换表由一个密钥字母表示,这个密钥字母就是用来代换明文字母A的。

设密钥为：k = k[0]k[1]...k[t-1]、明文为：m = m[0]m[1]...m[n-1]

则加密结果为：c=c[0]c[1]...c[n-1]

其中：c[i] = (m[i]+K[i]-‘a’) mod 26 + ‘a’（其中K[i]=k[i mod t]-‘a’）

例如密钥为big，明文为butcher，加密结果为cczdpks。

***

本次作业明文为附件plainText.txt，其中均为英文小写字母。密钥为每位同学自己的姓名小写全拼（如张三为zhangsan）。请编写程序读入附件，利用维吉尼亚加密算法加密后将密文输出到cipherText.txt中，提交加密程序以及密文文件cipherText.txt。

补充：简单起见，空格符和回车符不加密，正常输出。
例如，密钥为big，明文为a b c butcher，密文输出b j i cczdpks
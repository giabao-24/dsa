/*        A
        /   \
       B     C
      / \     \
     D   E     F */
Queue
buoc             thuchien           Queue           datham
khoitao        Them A               [A]              []
1              Lay A them C,B       [C,B]           [A]
2              Lay B them D,E       [C,D,E]         [A,B]
3              Lay C them F         [E,D,F]        [A,B,C]
4              Lay D                [E,F]          [A,B,C,D]
5              Lay E                [F]            [A,B,C,D,E]
6              Lay F                []             [A,B,C,D,E,F]
=> A-->C-->B-->F-->D-->E
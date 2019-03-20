10.2-1

INSERT可以，DELETE不行

10.2-2

在单链表的头部PUSH和POP即可

10.2-3

用两个指针分别代表head和tail，ENQUEUE时将head的next和head指向入队的元素，DEQUEUE时出队tail当前指向的元素并将tail指向tail的next

10.2-4

暂时令L.nil的key为k，在最后判断x和L.nil是否为同一个节点即可。

10.2-5

    INSERT(L, key):
    nex = L.nil.next
    pre = nex
    nex = nex.next
    while nex != L.nil
        if pre.key <= key and nex.key >= key
            new node.key = key
            pre.next = node
            node.next = nex
            return
        pre = nex
        nex = nex.next
    
    DELETE(L, key):
    f = L.nil
    pre = f
    f = f.next
    while f != L.nil and f.key <= key
        if f.key == key
            pre.next = f.next
            remove f from L
            return
        pre = f
        f = f.next

    SEARCH(L, key):
    f = L.nil.next
    while f != L.nil and f.key <= key
        if f.key == key
            return f
        f = f.next

时间复杂度都为:$\Omicron(n)$

10.2-6

链表，把两个链表的首尾链接起来构成一个链表包含$S_1$和$S_2$的所有元素。

10.2-7

用两个指针，把prev和next的指针反向链接起来，head指向最后一个元素即可。

10.3-2

与多数组表示法类似，不过是next从key下标位移+1的位置处拿到。

10.3-3

ALLOCATE-OBJECT不需要设置prev是将获取到的free节点插入到双向链表中时会按照插入位置初始化prev的值；FREE-OBJECT不需要重置prev是因为单链表没有使用prev中的值。

10.4-2

    RECURSIVE-TRAVERSE(root)
        if root != NIL
            print root
            RECURSIVE-TRAVERSE(root->left)
            RECURSIVE-TRAVERSE(root->right)

10.4-3

    NON-RECURSIVE-TRAVERSE(root)
        if root == NIL
            return
        stack.push(root)
        while stack not empty
            cur = stack.pop()
            print cur
            if cur->left != NIL
                stack.push(cur->left)
            if cur-right != NIL
                stack.push(cur->right)

10.4-4

与10.4-3过程一致，只是字段名有变化
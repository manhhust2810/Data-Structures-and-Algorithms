import java.lang.Integer;
import java.lang.String;

public class AVL {
    Node x;

    public void createTree(String strKey) {
        String s[] = strKey.split(" ");
        for (String w : s) {
            int a = Integer.valueOf(w);
            put(a);
        }
    }

    public void put(Integer key) {
        if (key == null)
            throw new IllegalArgumentException("It's a null key");
        x = put(x, key);
    }

    public Node put(Node x, Integer key) {
        if (x == null)
            return new Node(key, 1, 0);
        int cmp = key.compareTo(x.key);
        if (cmp < 0)
            x.left = put(x.left, key);
        else if (cmp > 0)
            x.right = put(x.right, key);
        else
            x.key = key;
        x.size = 1 + size(x.left) + size(x.right);

        int balance = checkBalance(x);
        if (balance > 1 && key < x.left.key)
            return rotateRight(x);
        if (balance < -1 && key > x.right.key)
            return rotateLeft(x);
        if (balance > 1 && key > x.left.key) {
            x.left = rotateLeft(x.left);
            return rotateRight(x);
        }
        if (balance < -1 && key < x.right.key) {
            x.right = rotateRight(x.right);
            return rotateLeft(x);
        }
        return x;
    }

    public Node balance(Node x) {
        if (checkBalance(x) < -1) {
            if (checkBalance(x.right) > 0) {
                x.right = rotateRight(x.right);
            }
            x = rotateLeft(x);
        } else if (checkBalance(x) > 1) {
            if (checkBalance(x.left) < 0) {
                x.left = rotateLeft(x.left);
            }
            x = rotateRight(x);
        }
        return x;
    }

    public int checkBalance(Node x) {
        if (x == null)
            return 0;
        return height(x.left) - height(x.right);
    }

    public Node rotateLeft(Node x) {
        Node y = x.right;
        x.right = y.left;
        y.left = x;
        y.size = x.size;
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.left), height(x.right));
        y.height = 1 + Math.max(height(y.left), height(y.right));
        return y;
    }

    public Node rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        y.size = x.size;
        x.size = 1 + size(x.left) + size(x.right);
        x.height = 1 + Math.max(height(x.left), height(x.right));
        y.height = 1 + Math.max(height(y.left), height(y.right));
        return y;
    }

    public int height(Node x) {
        if (x == null)
            return 0;
        else {
            int lHeight = height(x.left);
            int rHeight = height(x.right);
            if (lHeight > rHeight)
                return (lHeight + 1);
            else
                return (rHeight + 1);
        }
    }

    public int size(Node x) {
        if (x == null)
            return 0;
        else
            return x.size;
    }

    //Cau 2: 2
    public void lnr(Node x) {
        if (x != null) {
            lnr(x.left);
            System.out.print(x.key + " ");
            lnr(x.right);
        }
    }

    public int getMax(Node x){
        if(x.right == null) {   
            return x.key;
        }
        return getMax(x.right);
    }

    public static void main(String[] args) {
        AVL tree = new AVL();
        tree.createTree("60 32 51 85 23 15 2 46 75 36");
        tree.lnr(tree.x);
        System.out.println();
        System.out.println(tree.height(tree.x.right));
        System.out.println(tree.getMax(tree.x));
    }
}
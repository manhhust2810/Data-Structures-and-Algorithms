import java.lang.Integer;
import java.lang.String;

class BST {
	Node x;

	public BST() {
		x = null;
	}

	// cau 1
	public void createTree(String strKey) {
		String s[] = strKey.split(" ");
		for (String w : s) {
			int a = Integer.valueOf(w);
			put(a);
		}
	}

	// cau 4
	public void lnr(Node x) {
		if (x != null) {
			lnr(x.left);
			System.out.print(x.key + " ");
			lnr(x.right);
		}
	}

	// cau 2
	public void lrn(Node x) {
		if (x != null) {
			lrn(x.left);
			lrn(x.right);
			System.out.print(x.key + " ");
		}
	}

	public boolean contains(Node x, Integer key) {
		if (key == null)
			throw new IllegalArgumentException("Argument to contains() is null");
		return get(x, key) != null;
	}

	public Node get(Node x, Integer key) {
		if (key == null)
			return null;
		if (x == null)
			return null;
		int cmp = key.compareTo(x.key);
		if (cmp < 0)
			return get(x.left, key);
		else if (cmp > 0)
			return get(x.right, key);
		else
			return x;
	}

	// check tree and get right node (Phan 1: cau1: 3b)
	public void printRightNode(Node x, Integer key) {
		Node currentNode = get(x, key);

		if (currentNode == null) {
			System.out.println("Not found");
		} else {
			Node childCurrentNode = currentNode.right;
			lrn(childCurrentNode);
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
		return x;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	public int size() {
		return size(x);
	}

	public int size(Node x) {
		if (x == null)
			return 0;
		else
			return x.size;
	}

	public int height() {
		return height(x);
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

	// cau 6
	public Integer sum(Node x) {
		if (x == null)
			return 0;
		else
			return sum(x.left) + sum(x.right) + x.key;
	}

	// cau 7
	public Integer sum() {
		return sum(x);
	}

	public Node min(Node x) {
		if (x == null)
			return null;
		if (x.left == null)
			return x;
		else
			return min(x.left);
	}

	public Node deleteMin(Node x) {
		if (x.left == null)
			return x.right;
		x.left = deleteMin(x.left);
		size();
		height();
		return x;
	}

	public Node delete(Node x, Integer key) {
		if (x == null)
			return null;
		else {
			if (contains(x, key) == false)
				return null;
			else {
				int cmp = key.compareTo(x.key);
				if (cmp < 0)
					x.left = delete(x.left, key);
				else if (cmp > 0)
					x.right = delete(x.right, key);
				else {
					if (x.right == null)
						return x.left;
					if (x.left == null)
						return x.right;
					Node t = x;
					x = min(t.right);
					x.right = deleteMin(t.right);
					x.left = t.left;
					size();
					height();
				}
			}
			return x;
		}
	}

	public static void main(String arr[]) {
		BST tree = new BST();
		tree.createTree("60 32 51 85 23 15 2 46 75 36");
		// System.out.println(tree.get(tree.x, 32).right.size);
		// tree.printRightNode(tree.x, 32);
		tree.delete(tree.x, 32);
		System.out.println(tree.x.left.key);
	}
}

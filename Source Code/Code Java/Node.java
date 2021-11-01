class Node {
	Integer key;
	Node left, right;
	int size;
    int height;
    
    public Node() {
        
    }

	public Node(Integer key, int size, int height) {
		this.key = key;
		this.size = size;
		this.height = height;
	}
}
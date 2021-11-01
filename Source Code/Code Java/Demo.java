
public class Demo {
    public static void main(String[] args) {
        Graph g = new Graph("io.txt");
        Graph g1 = new Graph("io.txt");
        Graph g2 = new Graph("io.txt");
        Graph[] list = { g, g1, g2 };
        for (Graph item : list) {
            BFS bf = new BFS();
            bf.BFSAL(item);
        }
        // BFS bf = new BFS();
        // bf.BFSAL(g);
    }
}
/**
 * DFS
 */
public class DFS {

    private boolean[] check;

    public void DFS() {

    }

    public void DFSAL(Graph g) {
        System.out.println("DFS");
        this.check = new boolean[g.size];
        for (int i = 0; i < g.size; i++) {
            if (check[i] == false) {
                DFSUntil(i, g);
                System.out.println();
            }
        }
    }

    public void DFSUntil(int n, Graph g) {
        check[n] = true;
        System.out.print(n + "->");
        for (int i = 0; i < g.size; i++) {
            if (g.matrix[n][i] > 0 && check[i] == false) {
                DFSUntil(i, g);
            }
        }
    }
}
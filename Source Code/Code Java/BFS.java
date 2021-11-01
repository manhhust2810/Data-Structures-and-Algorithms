import java.util.LinkedList;
import java.util.Queue;

/**
 * BFS
 */
public class BFS {
  private boolean[] check;

  public void BFS() {

  }

  public void BFSAL(Graph g) {
    System.out.println("BFS");
    this.check = new boolean[g.size];
    for (int i = 0; i < g.size; i++) {
      if (check[i] == false) {
        BFSUntil(i, g);
        System.out.println();
      }
    }
  }

  public void BFSUntil(int n, Graph g) {
    check[n] = true;
    Queue<Integer> queue = new LinkedList<>();
    queue.add(n);
    while (!queue.isEmpty()) {
      System.out.print(queue.peek() + "->");
      int x = queue.poll();
      for (int i = 0; i < g.size; i++) {
        if (g.matrix[x][i] > 0 && check[i] == false) {
          queue.add(i);
          check[i] = true;
        }
      }
    }
  }
}
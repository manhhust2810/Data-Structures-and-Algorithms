import java.util.*;

class ArrayIndexComparator implements Comparator<Integer>
{
    private final Integer [] array;

    public ArrayIndexComparator(Integer [] array)
    {
        this.array = array;
    }

    public Integer[] createIndexArray()
    {
        Integer[] indexes = new Integer[array.length];
        for (int i = 0; i < array.length; i++)
        {
            indexes[i] = i; // Autoboxing
        }
        return indexes;
    }

    public int compare(Integer index1, Integer index2)
    {
        return array[index1].compareTo(array[index2])*-1;
    }
}

public class Bai1 {
    public static Integer [] tinhBac(int a[][]){
        Integer bac[] = new Integer[5];
        for(int i=0;i<5;i++)
        {
            int s=0;
            for(int j=0;j<5;j++)
            {
                s=s+a[i][j];
            }
            bac[i] = s;
        }
        return bac;
    }
    public static void main(String[] args) {
        final long startTime = System.currentTimeMillis();
        int graph[][] = {
                {0, 1, 1, 0, 1},
                {1, 0, 0, 0, 0},
                {1, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {1, 0, 1, 1, 0}
            };
        Integer bac[] = tinhBac(graph);
        ArrayIndexComparator comparator = new ArrayIndexComparator(bac);
        Integer[] v = comparator.createIndexArray();
        // sắp xếp
        Arrays.sort(v, comparator);

        // chuyển array sang list
        ArrayList<Integer> list = new ArrayList<>(Arrays.asList(v));

        int sm = 1;
        while (list.size() != 0){
            int current = list.get(0);
            list.remove(0);
            for (int j = 0; j < 5; j++) {
                if (graph[current][j] == 0 && list.contains(j)) {
                    sm++;
                    list.remove(Integer.valueOf(j));
                }
            }
        }
        System.out.print("Số màu là:" + sm);
        final long endTime = System.currentTimeMillis();

        System.out.println("\nTotal execution time: " + (endTime - startTime) + "ms");

    }
}


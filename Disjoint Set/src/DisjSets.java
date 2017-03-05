public class DisjSets {

	private int[] S;

	DisjSets(int numElements) {
		S = new int[numElements];
		makeset(numElements);
	}

	private void makeset(int n) {
		for (int i = 0; i < n; ++i)
			S[i] = -1;
	}

	void unionSets(int root1, int root2) {
		S[root2] = root1;
	}

	int find(int x) // path compression
	{
		if (S[x] < 0)
			return x;
		else
			return S[x] = find(S[x]);
	}

	void print()
   {
   for(int i=0;i<S.length;++i)
	   System.out.print(S[i]+" ");
   }

	public static void main(String[] args) {
		// simple test
		DisjSets d = new DisjSets(7);
		d.unionSets(0, 3);
		d.unionSets(3, 1);
		d.unionSets(1, 5);
		d.unionSets(2, 4);
		System.out.println(d.find(3));
	

	}

}

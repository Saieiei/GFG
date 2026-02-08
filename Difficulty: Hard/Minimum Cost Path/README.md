<h2><a href="https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1">Minimum Cost Path</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a square <strong>grid </strong>of size <strong>N</strong>, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a <strong>path</strong> from the <strong>top</strong> <strong>left</strong> cell to the <strong>bottom</strong> <strong>right</strong> cell by which the total cost incurred is <strong>minimum</strong>.<br>From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). </span>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>grid = [[9,4,9,9],<br>               [6,7,6,4],<br>               [8,3,3,7],<br>               [7,4,9,10]]
<strong>Output: </strong>43
<strong>Explanation: </strong>The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>grid = [[4,4],<br>               [3,7]]
<strong>Output: </strong>14
<strong>Explanation: </strong>The minimum cost is- 4 + 3 + 7 = 14.</span>
</pre>
<pre><strong><span style="font-size: 18px;">Constraints:</span></strong><br><span style="font-size: 18px;">1 ≤ n ≤ 500<br>1 ≤ cost of cells ≤ 500</span></pre></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Heap</code>&nbsp;
# [Gold II] Bessie's Dream - 11965 

[문제 링크](https://www.acmicpc.net/problem/11965) 

### 성능 요약

메모리: 13996 KB, 시간: 120 ms

### 분류

구현, 그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 데이크스트라

### 제출 일자

2026년 3월 2일 12:36:27

### 문제 설명

<p>After eating too much fruit in Farmer John's kitchen, Bessie the cow is getting some very strange dreams! In her most recent dream, she is trapped in a maze in the shape of an <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N \times M\)</span></mjx-container> grid of tiles (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>,</mo><mi>M</mi><mo>≤</mo><mn>1</mn><mo>,</mo><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(1 \le N, M \le 1,000\)</span></mjx-container>). She starts on the top-left tile and wants to get to the bottom-right tile. When she is standing on a tile, she can potentially move to the adjacent tiles in any of the four cardinal directions.</p>

<p>But wait! Each tile has a color, and each color has a different property! Bessie's head hurts just thinking about it:</p>

<ul>
	<li>If a tile is <strong>red</strong>, then it is impassable.</li>
	<li>If a tile is <strong>pink</strong>, then it can be walked on normally.</li>
	<li>If a tile is <strong>orange</strong>, then it can be walked on normally, but will make Bessie smell like oranges.</li>
	<li>If a tile is <strong>blue</strong>, then it contains piranhas that will only let Bessie pass if she smells like oranges.</li>
	<li>If a tile is <strong>purple</strong>, then Bessie will slide to the next tile in that direction (unless she is unable to cross it). If this tile is also a purple tile, then Bessie will continue to slide until she lands on a non-purple tile or hits an impassable tile. Sliding through a tile counts as a move. <strong>Purple tiles will also remove Bessie's smell.</strong></li>
</ul>

<p>(If you're confused about purple tiles, the example will illustrate their use.)</p>

<p>Please help Bessie get from the top-left to the bottom-right in as few moves as possible.</p>

### 입력 

 <p>The first line has two integers <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container> and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(M\)</span></mjx-container>, representing the number of rows and columns of the maze.</p>

<p>The next <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container> lines have <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(M\)</span></mjx-container> integers each, representing the maze:</p>

<ul>
	<li>The integer '0' is a red tile</li>
	<li>The integer '1' is a pink tile</li>
	<li>The integer '2' is an orange tile</li>
	<li>The integer '3' is a blue tile</li>
	<li>The integer '4' is a purple tile</li>
</ul>

<p>The top-left and bottom-right integers will always be '1'.</p>

### 출력 

 <p>A single integer, representing the minimum number of moves Bessie must use to cross the maze, or -1 if it is impossible to do so.</p>


---
title: ds/doubling.cpp
documentation_of: ../../ds/doubling.cpp
---

## constructor

`doubling(LOG, to)`: build a doulbing table with jump gap $2^i$ for all $0 \leq i < \text{LOG}$, all elements of $\text{to}$ should be integer between $-1$ and $|to| - 1$.

`doubling(LOG, to, init, id, f)`: build a doubling table with monoid(id, f) attached where $\text{init[v]}$ is the data attach on the edge from $v$ to $\text{to[v]}$

## functions

`jump(v, k)`: return the destination when jump from $v$ by $k$ steps. $-1$ if such destination does not exist

`jump(v, k)` (with monoid attached): also return the product of monoid along the jump trail

`jump_while_true(v, pred)`: jump to the last vertex $u$ where $pred(u)$ holds. if $pred(v)$ is false, return $v$.

`jump_while_true(v, pred)` (with monoid attached): prediate also take the accumulated product along the path as argument. And return the accumulated product from $v$ to $u$.

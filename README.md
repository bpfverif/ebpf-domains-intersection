## Run

```
$ make
$ ./intersection.out
allwise: 0
pairwise: 1
```

## Allwise intersection between all eBPF domains

That there are arbitrary (not constant) number of u/s-32 intervals in the 64-bit
concrete space. However, those intervals are periodic, and this periodicity
renders most of those intervals redundant.  Hence, we can narrow down
intersection checking to a small number of "interesting" 32-bit subspaces, i.e.
u64 intervals with sizes 2^32 and whose boundaries are aligned to 32-bits (i.e.,
n<<32 for some n). We need to guarantee that a small (constant) number of such
subspaces contain an intersection if one exists in the global 64-bit concrete
space, and that we can find those subspaces efficiently (e.g. constant time).

Tnums only slightly complicate this high-level approach because the higher and
lower-order 32 bits of the tnum are separable.  If the higher-order 32 bits of
the tnum permit inhabiting a 32-bit subspace, we can run an independent
intersection with only the lower-order 32 bits (e.g., u32, s32, and tnum32)
within that subspace.

The question then is how to identify a small but complete set of 32-bit
subspaces that guarantee finding an intersecting element if one exists.

High-level approach:

1. Set intersection is associative.  First compute the exact intersection of u64
and s64. There can be at most two resulting u64 intervals.

2. Each interval from (1) above [x,y] is either

    1. a u64 interval which is fully contained inside one 32-bit subspace, i.e.
with the form (n<<32) < x <= y < (n<<32|int32_max) for some n OR

    2. a union of at most three u64 intervals consisting of a "left edge", a
sequence of full 32-bit subspaces, and a "right edge". Suppose `x = x_hi<<32 |
x_lo` and `y = y_hi<<32 | y_lo`, we have at most three intervals whose union is [x,y]:

        - the "left" edge `[x_hi<<32 | x_lo, x_hi<<32 | int32_max]`

        - concatenation of full 32-bit subspaces `[(x_hi+1) << 32, (y_hi<<32) - 1]`

        - the "right" edge `[y_hi<<32, y_hi<<32 | y_lo]`

  In total, there are at most 2 * 3 = 6 such sub-intervals. Breaking up the
intervals in this way allows us to zoom into the non-redundant 32-bit subspaces
in the next steps.

3. For each u64 interval from (2) above, run a tnum-u64 intersection. Discard
intervals with no intersections. For the rest, form (at most 6) u32 intervals by
keeping the lower-order 32 bits of the corresponding u64 intervals. This
"pre-intersection" operation with tnum helps filter out 32-bit subspaces whose
higher-order 32 bits disagree with the tnum.

4. For each u32 interval from (3) above, intersect tnum32, u32, and s32, by
iterating using the multi-domain step function. This is a constant time
operation. If any of the (at most 6) intersection checks returns nonempty, we
have a nonempty allwise intersection. At any point above if we are left with an
empty list, the allwise intersection is empty.
 
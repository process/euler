from copy import deepcopy as dc

"""
Welp,  I definitely overthought this one.
I assumed there would be duplicate characters in the password and had
trouble deriving a reliable algorithm from that.

My solution generates a trie of the attempted password. I then do a weighted
search through possible paths to find the most efficient one. This can find
optimal solutions where there are duplications or loops in the attempts.

For example, `112 212` will find `2112` and `1212` as solutions.

However, the true solution does not have any duplicates or special cases,
so can be found by simply finding the right way to combine all the attempts.

Oops!
"""

def merge_dict(d1, d2):
  for key in d2.keys():
    if key in d1:
      merge_dict(d1[key], d2[key])
    else:
      d1[key] = d2[key]

def remove_node_and_merge(t, k):
  children = t[k]
  del t[k]
  merge_dict(t, children)
  return t

def get_tree(tree, candidate):
  t = dc(tree)
  for c in candidate:
    remove_node_and_merge(t, c)
  return t

def count_leaves(tree, key):
  if not tree[key]:
    return 1
  count = 0
  for k in tree[key].keys():
    count += count_leaves(tree[key], k)
  return count

# Main code
successes = open("res/p079_keylog.txt").readlines()
successes = [s.strip() for s in successes]
successes = list(set(successes))

pseudo_trie = {}
for s in successes:
  current_dict = pseudo_trie
  for c in s:
    if c not in current_dict:
      current_dict[c] = {}
    current_dict = current_dict[c]

# adjusted_count -> (path, total_count)
possible_paths = {}
ps = dc(pseudo_trie)
for k in ps.keys():
  count = len(ps[k])
  if count not in possible_paths:
    possible_paths[count] = []
  possible_paths[count].append((k,
                                len(ps[k])))

iter_count = 0
while possible_paths:
  iter_count += 1
  best_count = sorted(possible_paths.keys())[-1]
  current = possible_paths[best_count][0]
  cur_path, cur_total_count = current
  cur_tree = get_tree(ps, cur_path)
  if not cur_tree:
      print "ANSWER: ", cur_path
      print "Length: ", len(cur_path), "; Iterations: ", iter_count
      break
  else:
    for k in cur_tree.keys():
      new_path = cur_path + k
      new_total_count = cur_total_count + count_leaves(cur_tree, k)
      new_adjusted_count = float(new_total_count) / len(new_path)
      if new_adjusted_count not in possible_paths:
        possible_paths[new_adjusted_count] = []
      possible_paths[new_adjusted_count].append((new_path,
                                                 new_total_count))
  possible_paths[best_count].remove(current)
  if not possible_paths[best_count]:
    del possible_paths[best_count]

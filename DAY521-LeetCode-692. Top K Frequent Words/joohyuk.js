/**
 * @param {string[]} words
 * @param {number} k
 * @return {string[]}
 */

var topKFrequent = function(words, k) {
  const t = {}
  for (const word of words) t[word] = t[word] + 1 || 1
  return Object.keys(t).sort((a, b) => (t[a]===t[b])?a>b?1:-1:t[b]-t[a]).slice(0, k)
}

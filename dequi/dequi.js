function dequi(n) {
  if (n === 0) {
    return 0;
  }
  return n + dequi(n - 1);
}
console.log(dequi(5)); // Output: 5

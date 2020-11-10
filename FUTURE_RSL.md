#### accumulate_until

```cpp
// From
template <>
uint64_t container::get_encoded()
{
  uint64_t val = 0;
  for (uint64_t len = 0; len < 64; len += 7) {
    auto const byte = get_raw<uint8_t>();
    val |= (byte & 0x7f) << len;
    if (byte < 0x80) break;
  }
  return val;
}

// To
template <>
uint64_t container::get_encoded()
{
  return accumulate_until(
    rv::iota(0, 64, 7), 
    uint64_t{0}, 
    [] (auto acc, auto e) {
      auto const byte = get_raw<uint8_t>();
      return acc | (byte & 0x7f) << len;
    [] (auto e) { return byte < 0x80; }); // this is technically wrong
}
```

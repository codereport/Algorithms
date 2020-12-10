
## Returning a no-op on `cudf::column`

|Situation|Code|
|:-:|:-:|
|When empty|`return empty_like(input);`|
|When not empty|`return std::make_unique<cudf::column>(input, stream, mr);`|

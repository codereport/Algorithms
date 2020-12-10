
## Returning a no-op on `cudf::column`

|Situation|Code|
|:-:|:-:|
|When empty|`return empty_like(input);`|
|When not empty|`return std::make_unique<cudf::column>(input, stream, mr);`|

## Constructing / accessing `cudf::type_id`

|Situation|Code|
|:-:|:-:|
|Compile `T` available|`data_type{type_to_id<T>()}`|
|Compile `T` not available|`input.type().id()`|

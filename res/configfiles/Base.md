# Base

## Summary
The base is what the player needs to defend in the game Tower Defence. It's position is at the end of the predefined route the enemies walk and every time an [enemy](/master/res/configfiles/Enemies.md) reaches it the base takes damage. When the health reaches 0 the player loses.

<br>
<details open>
<summary> An example of how towers are defined</summary>

---

```json
"base":{
    "health": 100,
    "textureFile": "../res/images/planet.png"
}
```

</details>



<br>

## How to create a base

<details>
<summary> Creating a base  :european_castle: </summary>
Create a property called "base" and follow the other steps to configure it's properties.
<br>

* The name has to be "base"
* It contains it's own health and path to it's texture
* When "base" is not defined it will crash the game.

```json
"base":{...}
```

</details>
<br>

<details>
<summary> Setting a base's health :two_hearts: </summary>
Add a property "health" to your base and give it a value of your desired health.
<br>

* The default value is 0
* The type is a float

```json
"base":{
    "health":100,
    ...
}
```

</details>
<br>

<details>
<summary> Setting a base's texture  :framed_picture:  </summary>
Add a property "textureFile" to your base and give it a value of the path to your desired texture.
<br>

* When the program cannot find the texture, the texture will be a white square.
* The type is a string
* When "textureFile" is not defined it will crash the game.

```json
"base":{
    "health":100,
    "textureFile": "../res/images/planet.png"
}
```

</details>
<br>

## Links

[Waves](/res/configfiles/Waves.md)
<br>
[Enemies](/res/configfiles/Enemies.md)
<br>
[Towers](/res/configfiles/Towers.md)
<br>
[Map](/res/configfiles/Map.md)


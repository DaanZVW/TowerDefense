# Base

## Summary
The base is what the player needs to defend in the game Tower Defence. It's position is at the end of the predefined route the [Enemies](/DaanZVW/TowerDefense/blob/master/res/configfiles/Enemies.md) walk and every time an enemy reaches it the [Base](/DaanZVW/TowerDefense/blob/master/res/configfiles/Base.md) takes damage. When the health reaches 0 the player loses.

<br>
<details open>
<summary> An example of how towers are defined</summary>

---

```json
{ 
    "Info" :
    {
        "Difficulty" : "Easy",
        "Name" : "Angry Shroom",
        "GridSize" : [20, 15],
        "BeginMoney" : 300,
        "RandomObjects" : 150
    },
    "PathNodes": 
    [
        {
            "x" : -1,
            "y" : 3
        },
        {
            "x" : 10,
            "y" : 3
        }
    ]
}
```

<br>

## How to create a new tower


<details>
<summary> Creating a map  :european_castle: </summary>
Create an item containing the properties "Info" and "PathNodes".
<br>

* The names have to be "Info" and "PathNodes"
* When "Info" and "PathNodes" are not defined it will crash the game.

```json
{
    "Info":{...},
    "PathNodes":[...]
}
```

</details>
<br>

<details>
<summary> Setting the name :capital_abcd: </summary>
Create a property in "Name" containing your desired name.
<br>

* the type of the value is a string

```json
{
    "Info":{
        "Name" : "Angry Shroom",
        ...
        },
    "PathNodes":[...]
}
```

</details>
<br>

<details>
<summary> Defining the difficulty :cowboy_hat_face: </summary>
Create a property in "Difficulty" containing your desired difficulty. This is nothing more than just a name. This does not change anything other that the name.
<br>

* the type of the value is a string

```json
{
    "Info":{
        "Name" : "Angry Shroom",
        "Difficulty":"easy",
        ...
        },
    "PathNodes":[...]
}
```

</details>
<br>

<details>
<summary> Setting the map size  :1234: </summary>
Create a property in "Size" containing your desired size. 
<br>

* the type of the value is an array containing 2 unsigned integers

```json
{
    "Info":{
        "Name" : "Angry Shroom",
        "Difficulty":"easy",
        "GridSize" : [20, 15],
        ...
        },
    "PathNodes":[...]
}
```

</details>
<br>

<details>
<summary> Setting the begin money :moneybag: </summary>
Create a property in "BeginMoney" containing your desired amount of money. 
<br>

* the default value is 0.
* the type of the value is an unsigned integer

```json
{
    "Info":{
        "Name" : "Angry Shroom",
        "Difficulty":"easy",
        "GridSize" : [20, 15],
        "BeginMoney" : 300,
        ...
        },
    "PathNodes":[...]
}
```

</details>
<br>

<details>
<summary> Setting the amount of random objects :moyai: </summary>
Create a property in "RandomObjects" containing your desired amount of randomObjects. 
<br>

* the default value is 0.
* the type of the value is an unsigned integer.

```json
{
    "Info":{
        "Name" : "Angry Shroom",
        "Difficulty":"easy",
        "GridSize" : [20, 15],
        "BeginMoney" : 300,
        "RandomObjects" : 150
        },
    "PathNodes":[...]
}
```

</details>
<br>


<details>
<summary> Adding nodes in PathNodes :round_pushpin: </summary>
Create an item in "in PathNodes" containing your desired path node location. 
<br>

* When no PathNodes are given no path will be created.
* the type of the value 1 or more items containing an "x" and an "y" value of which both are integers.
* paths will be created between the nodes.
* if the x y spot is not within the size of the grid it wont get displayed.

```json
{
    "Info":{
        "Name" : "Angry Shroom",
        "Difficulty":"easy",
        "GridSize" : [20, 15],
        "BeginMoney" : 300,
        "RandomObjects" : 150
        },
    "PathNodes":[
        {
            "x" : -1,
            "y" : 3
        },
        {...}
    ]
}
```

</details>
<br>

## Links

[Base](/DaanZVW/TowerDefense/blob/master/res/configfiles/Base.md)
<br>
[Waves](/DaanZVW/TowerDefense/blob/master/res/configfiles/Waves.md)
<br>
[Enemies](/DaanZVW/TowerDefense/blob/master/res/configfiles/Enemies.md)
<br>
[Towers](/DaanZVW/TowerDefense/blob/master/res/configfiles/Towers.md)

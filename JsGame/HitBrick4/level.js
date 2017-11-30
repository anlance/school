var levels = [
    [
        [100, 100, 1],
    ],
    [
        [0, 0, 1],
        [100, 100, 1],
    ],
    [
        [50, 30, 1],
        [100, 100, 2],
        [200, 100, 2],
    ],
]

window.toLevel = 0
var loadLevel = function(game, n){
    n = n - 1
    var level = levels[n]
    log('s', levels.length)
    var blocks = []
    window.toLevel = 0
    for(var i = 0; i < level.length; i++){
        var p = level[i]
        window.toLevel += p[2]
        var b = Block(game, p)
        //设置 block 坐标
        blocks.push(b)
    }
    return blocks
}

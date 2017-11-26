var SceneEnd = function (game) {
    var s = {
        game: game,
    }
    

    s.draw = function () {
        //draw labels
        game.context.fillText('游戏结束', 100,200)
    }
    s.update = function () {
        
    }
    return s
}
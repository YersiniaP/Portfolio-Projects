function editzookeeper(keeper_id){
    $.ajax({
        url: '/zookeepers/' + keeper_id,
        type: 'PUT',
        data: $('#text_box1').serialize(),
        success: function(result){
            window.location.reload(true);
        }
    })
};

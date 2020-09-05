function deleteZookeeper(keeper_id){
    $.ajax({
        url: '/zookeepers/' + keeper_id,
        type: 'DELETE',
        success: function(result){
            window.location.reload(true);
        }
    })

};
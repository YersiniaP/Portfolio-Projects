function editanimal(animal_id){
    $.ajax({
        url: '/animals/' + animal_id,
        type: 'PUT',
        data: $('#text_box1').serialize(),
        success: function(result){
            window.location.reload(true);
        }
    })
};

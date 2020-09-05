function deleteanimal(animal_id){
    $.ajax({
        url: '/animals/' + animal_id,
        type: 'DELETE',
        success: function(result){
            window.location.reload(true);
        }
    })

};
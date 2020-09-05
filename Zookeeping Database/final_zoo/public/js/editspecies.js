function editspecies(species_id){
    $.ajax({
        url: '/species/' + species_id,
        type: 'PUT',
        data: $('#text_box1').serialize(),
        success: function(result){
            window.location.reload(true);
        }
    })
};

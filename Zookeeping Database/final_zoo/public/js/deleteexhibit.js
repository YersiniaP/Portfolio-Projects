function deleteExhibit(exhibit_id){
    $.ajax({
        url: '/exhibits/' + exhibit_id,
        type: 'DELETE',
        success: function(result){
            window.location.reload(true);
        }
    })

};
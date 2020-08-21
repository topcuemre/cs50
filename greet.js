function greet()
{
    let name = document.querySelector('#name').value;
    if(name==='')
    {
     name = 'world';
    }
    document.querySelector('#result').innerHTML = 'Hello ' + name + '!';
}
     
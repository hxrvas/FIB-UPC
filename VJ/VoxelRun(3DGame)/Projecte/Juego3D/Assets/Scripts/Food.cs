using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Food : MonoBehaviour
{
    float starty;
    bool baixar;
    private void Start()
    {
        starty = transform.position.y;
        baixar = false;
    }
    private void Update()
    {
        Vector3 y = new Vector3(0, 1, 0);
        transform.Rotate(y, 60f * Time.deltaTime);


        if (transform.position.y >= starty+1f) baixar = true;

        else if (transform.position.y <= starty) baixar = false;

        if (baixar) transform.Translate(0, -0.5f * Time.deltaTime, 0);
        else transform.Translate(0, +0.5f * Time.deltaTime, 0);

    }
    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Player"))
        {
            FindObjectOfType<AudioManager>().Play("Eat");
            Movement player = other.gameObject.GetComponent<Movement>();
            player.addScale(2);
            Destroy(this.gameObject);
        }
    }
}

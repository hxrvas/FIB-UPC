using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GiratoriTrigger : MonoBehaviour
{
    void OnTriggerEnter(Collider collision)
    {

        if (collision.gameObject.tag == "Player")
        {
            //collision.gameObject.GetComponent<Movement>().Brotating();
            //collision.transform.parent = this.transform;
            //collision.gameObject.GetComponent<Movement>().setPointFix(transform);
            //collision.gameObject.GetComponent<Movement>().setUp(transform.up);
        }


    }

    void OnTriggerExit(Collider collision)
    {
        if (collision.gameObject.tag == "Player")
        {
           // collision.gameObject.GetComponent<Movement>().Nrotating();
            //collision.transform.parent = null;
        }
    }
}

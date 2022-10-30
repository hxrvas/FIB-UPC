using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Slime : MonoBehaviour
{
    void OnTriggerStay(Collider collision)
    {
            //Check for a match with the specified name on any GameObject that collides with your GameObject
            if (collision.gameObject.tag == "Player")
            {


                Movement player = collision.gameObject.GetComponent<Movement>();

                    player.ActivateSlowDown();
            }
    }

    void OnTriggerExit(Collider collision)
    {
        //Check for a match with the specified name on any GameObject that collides with your GameObject
        if (collision.gameObject.tag == "Player")
        {


            Movement player = collision.gameObject.GetComponent<Movement>();

                player.DeactivateSlowDown();
        }
    }
}

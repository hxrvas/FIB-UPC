using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TriggerChangeOrDie : MonoBehaviour
{
    public GameLogic logic;
    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Player"))
        {
            logic.changeOrDie = true;
        }
    }
}
